
/**
 * Copyright (C) Anny Wang.
 * Copyright (C) Hupu, Inc.
 */

#ifndef _W_MEM_POOL_H_
#define _W_MEM_POOL_H_

#include <vector>
#include "wCore.h"
#include "wNoncopyable.h"

namespace hnet {

class wMemPool : private wNoncopyable {
public:
    wMemPool(): mAllocPtr(NULL), mAllocRemaining(0), mBlocksMemory(0) { }
    ~wMemPool();

    char* Allocate(size_t bytes);
    char* AllocateAligned(size_t bytes);

    size_t MemoryUsage() const {
        return mBlocksMemory + mBlocks.capacity() * sizeof(char*);
    }

protected:
    enum { kBlockSize = kPageSize};
    char* AllocateFallback(size_t bytes);
    char* AllocateNewBlock(size_t block_bytes);

    char* mAllocPtr;
    size_t mAllocRemaining;
    size_t mBlocksMemory;
    std::vector<char*> mBlocks;
};

}   // namespace hnet

#endif