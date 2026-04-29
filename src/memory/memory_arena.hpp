#pragma once
#include <cstddef>

class MemoryArena{
private:
    char* data{nullptr};
    size_t capacity{0};
    size_t offset{0};

    MemoryArena(const MemoryArena&) = delete;
    MemoryArena& operator=(const MemoryArena&) = delete;

public:
    MemoryArena();
    explicit MemoryArena(size_t memAllocation);
    ~MemoryArena();

    void* allocate(size_t size);
};