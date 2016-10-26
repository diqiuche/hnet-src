
/**
 * Copyright (C) Anny Wang.
 * Copyright (C) Hupu, Inc.
 */

#ifndef _W_MMAP_H_
#define _W_MMAP_H_

#include <sys/mman.h>
#include "wCore.h"
#include "wNoncopyable.h"

namespace hnet {
// 内存映射
class wMmap : private wNoncopyable {
public:
	// mmap必须以PAGE_SIZE为单位进行映射，而内存也只能以页为单位进行映射，
	// 若要映射非PAGE_SIZE整数倍的地址范围，要先进行内存对齐，强行以PAGE_SIZE的倍数大小进行映射
	// fd = -1 & flags = MAP_ANONYMOUS 匿名映射，只用于具有亲缘关系的进程间通信
	wMmap(const char *filename, int flags = MAP_SHARED, size_t size = 0, int prot = PROT_READ| PROT_WRITE,  off_t offset = 0, void *start = NULL, int fd = -1) {
		memcpy(mFilename, filename, strlen(filename)+1);
		mSize = misc:Align(size, kBlockSize);
		mStart = mmap(start, size, prot, flags, fd, offset);
	}
	~wMmap() { return munmap(mStart, mSize);}
private:
	int mFD;
	char mFilename[255];
	void *mStart;
	size_t mSize;
};

}	// namespace

#endif
