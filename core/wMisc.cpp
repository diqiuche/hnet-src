
/**
 * Copyright (C) Anny Wang.
 * Copyright (C) Hupu, Inc.
 */

#include <pwd.h>
#include <grp.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include "wMisc.h"

namespace hnet {
namespace coding {

void EncodeFixed32(char* buf, uint32_t value) {
    if (kLittleEndian) {
        memcpy(buf, &value, sizeof(value));
    } else {
        buf[0] = value & 0xff;
        buf[1] = (value >> 8) & 0xff;
        buf[2] = (value >> 16) & 0xff;
        buf[3] = (value >> 24) & 0xff;
    }
}

void EncodeFixed64(char* buf, uint64_t value) {
    if (kLittleEndian) {
        memcpy(buf, &value, sizeof(value));
    } else {
        buf[0] = value & 0xff;
        buf[1] = (value >> 8) & 0xff;
        buf[2] = (value >> 16) & 0xff;
        buf[3] = (value >> 24) & 0xff;
        buf[4] = (value >> 32) & 0xff;
        buf[5] = (value >> 40) & 0xff;
        buf[6] = (value >> 48) & 0xff;
        buf[7] = (value >> 56) & 0xff;
    }
}

void PutFixed32(std::string* dst, uint32_t value) {
    char buf[sizeof(value)];
    EncodeFixed32(buf, value);
    dst->append(buf, sizeof(buf));
}

void PutFixed64(std::string* dst, uint64_t value) {
    char buf[sizeof(value)];
    EncodeFixed64(buf, value);
    dst->append(buf, sizeof(buf));
}

}	// namespace coding

namespace logging {

void AppendNumberTo(std::string* str, uint64_t num) {
    char buf[30];
    snprintf(buf, sizeof(buf), "%llu", (unsigned long long) num);
    str->append(buf);
}

void AppendEscapedStringTo(std::string* str, const wSlice& value) {
    for (size_t i = 0; i < value.size(); i++) {
        char c = value[i];
        if (c >= ' ' && c <= '~') {		// 可见字符范围
            str->push_back(c);
        } else {
            char buf[10];
            // 转成\x[0-9]{2} 16进制输出，前缀补0
            snprintf(buf, sizeof(buf), "\\x%02x", static_cast<unsigned int>(c) & 0xff);
            str->append(buf);
        }
    }
}

std::string NumberToString(uint64_t num) {
    std::string r;
    AppendNumberTo(&r, num);
    return r;
}

std::string EscapeString(const wSlice& value) {
    std::string r;
    AppendEscapedStringTo(&r, value);
    return r;
}

bool ConsumeDecimalNumber(std::string* in, uint64_t* val) {
    uint64_t v = 0;
    int digits = 0;
    while (!in->empty()) {
        char c = (*in)[0];
        if (c >= '0' && c <= '9') {
            ++digits;
            const int delta = (c - '0');
            static const uint64_t kMaxUint64 = ~static_cast<uint64_t>(0);
            if (v > kMaxUint64/10 || (v == kMaxUint64/10 && static_cast<uint64_t>(delta) > kMaxUint64%10)) {
                return false;	// 转化uint64溢出
            }
            v = (v * 10) + delta;
            in->assign(*in, 1, in->size()-1);
        } else {
            break;
        }
    }
    *val = v;
    return (digits > 0);
}

}	// namespace logging

namespace misc {

static inline void FallThroughIntended() { }

uint32_t Hash(const char* data, size_t n, uint32_t seed) {
    const uint32_t m = 0xc6a4a793;
    const uint32_t r = 24;
    const char* limit = data + n;
    uint32_t h = seed ^ (n * m);

    // Pick up four bytes at a time
    while (data + 4 <= limit) {
        uint32_t w = coding::DecodeFixed32(data);
        data += 4;
        h += w;
        h *= m;
        h ^= (h >> 16);
    }

    switch (limit - data) {
        case 3:
        h += static_cast<unsigned char>(data[2]) << 16;
        FallThroughIntended();
        
        case 2:
        h += static_cast<unsigned char>(data[1]) << 8;
        FallThroughIntended();

        case 1:
        h += static_cast<unsigned char>(data[0]);
        h *= m;
        h ^= (h >> r);
        break;
    }
    return h;
}

void Strlow(u_char *dst, u_char *src, size_t n) {
    do {
        *dst = tolower(*src);
        dst++;
        src++;
    } while (--n);
}

u_char *Cpystrn(u_char *dst, u_char *src, size_t n) {
    if (n == 0) return dst;

    while (--n) {
        *dst = *src;
        if (*dst == '\0') {
            return dst;
        }
        dst++;
        src++;
    }
    *dst = '\0';
    return dst;
}

static uint64_t Gcd(uint64_t a, uint64_t b) {
    if (a < b) Swap(a, b);
    if (b == 0) return a;
    return Gcd(b, a % b);
}

uint64_t Ngcd(uint64_t *arr, size_t n) {
    if (n <= 1)  return arr[n-1];
    return Gcd(arr[n-1], Ngcd(arr, n-1));
}

unsigned GetIpByIF(const char* ifname) {
    unsigned ip = 0;
    ssize_t fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd >= 0) {
        struct ifconf ifc = {0, {0}};
        struct ifreq buf[64];
        memset(buf, 0, sizeof(buf));
        ifc.ifc_len = sizeof(buf);
        ifc.ifc_buf = reinterpret_cast<caddr_t>(buf);
        if (!ioctl(fd, SIOCGIFCONF, (char*)&ifc)) {
            size_t interface = ifc.ifc_len / sizeof(struct ifreq); 
            while (interface-- > 0) {
                if (strcmp(buf[interface].ifr_name, ifname) == 0) {
                    if (!ioctl(fd, SIOCGIFADDR, reinterpret_cast<char *>(&buf[interface]))) {
                        ip = reinterpret_cast<unsigned>((reinterpret_cast<struct sockaddr_in*>(&buf[interface].ifr_addr))->sin_addr.s_addr);
                    }
                    break;  
                }
            }
        }
        close(fd);
    }
    return ip;
}

wStatus InitDaemon(const char *lockfile, const char *prefix) {
    // 获取主目录
    char dirPath[256] = {0};
    if (prefix == NULL) {
        if (getcwd(dirPath, sizeof(dirPath)) == NULL) {
            return wStatus::Corruption("misc::InitDaemon, getcwd failed", strerror(errno));
        }
    } else {
        memcpy(dirPath, prefix, strlen(prefix) + 1);
    }

    if (chdir(dirPath) == -1) {
        return wStatus::Corruption("misc::InitDaemon, chdir failed", strerror(errno));
    }
    umask(0);

    // 独占式锁定文件，防止有相同程序的进程已经启动
    lockfile = lockfile != NULL? lockfile: kLockPath;
    int lockFD = open(lockfile, O_RDWR|O_CREAT, 0640);
    if (lockFD < 0) {
        return wStatus::IOError("misc::InitDaemon, open lockfile failed", strerror(errno));
    }
    if (flock(lockFD, LOCK_EX | LOCK_NB) < 0) {
        return wStatus::IOError("misc::InitDaemon, flock lockfile failed(maybe server is already running)", strerror(errno));
    }

    // 若是以root身份运行，设置进程的实际、有效uid
    if (geteuid() == 0) {
        if (setuid(kDeamonUser) == -1) {
            return wStatus::Corruption("misc::InitDaemon, setuid failed", strerror(errno));
        }
        if (setgid(kDeamonGroup) == -1) {
            return wStatus::Corruption("misc::InitDaemon, setgid failed", strerror(errno));
        }

        /*
        // 附加组ID
        if (initgroups(kDeamonUser, kDeamonGroup) == -1) {
            // initgroups failed
        }
        */
    }

    if (fork() != 0) {
        exit(0);
    }
    setsid();
    
    // 忽略以下信号
    wSignal stSig(SIG_IGN);
    stSig.AddSigno(SIGINT);
    stSig.AddSigno(SIGHUP);
    stSig.AddSigno(SIGQUIT);
    stSig.AddSigno(SIGTERM);
    stSig.AddSigno(SIGCHLD);
    stSig.AddSigno(SIGPIPE);
    stSig.AddSigno(SIGTTIN);
    stSig.AddSigno(SIGTTOU);

    if (fork() != 0) {
        exit(0);
    }
    unlink(lockfile);
    return wStatus::Nothing();
}

}	// namespace misc
}	// namespace hnet
