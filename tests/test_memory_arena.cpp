#include <iostream>
#include <memory_arena.hpp>

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