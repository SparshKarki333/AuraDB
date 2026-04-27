#include <iostream>

#include "memory_arena.hpp"

MemoryArena::MemoryArena() : data(nullptr), capacity(0), offset(0){}

MemoryArena::MemoryArena(size_t memAllocation){
    if (memAllocation > 0){
        data  = new char[memAllocation];
        capacity = memAllocation;
        offset = 0;
    }
}

MemoryArena::~MemoryArena(){
    delete[] data;
}

void* MemoryArena::allocate(size_t size){
    if (offset + size > capacity){
        return nullptr;
    }
    void* ptr = static_cast<void*>(data + offset);
    offset +=size;
    return ptr;
}

int main(){
    MemoryArena arena(1024);

    void* mem = arena.allocate(sizeof(int));

    if (mem == nullptr){
        std::cerr << "Allocation failed! \n";
    }
    int* p = static_cast<int*>(mem);
    *p = 42;
    std::cout << "Value stored: " << *p << std::endl;
}