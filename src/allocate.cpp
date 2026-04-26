#include <iostream>

/*
size_t is used to represent the size of objects/variables in bytes.
sizeof returns this data type only.
*/

class MemoryArena{
private:
    char* data{nullptr};
    size_t capacity{0}; //total bytes allocated
    size_t offset{0}; //total bytes handed out
    MemoryArena(const MemoryArena&) = delete;
    MemoryArena& operator=(const MemoryArena&) = delete;
public:
    //Default Constructor
    MemoryArena() : data(nullptr), capacity(0), offset(0){}

    //Parameterized Constructor
    MemoryArena(size_t memAllocation){
        if (memAllocation > 0){
            data = new char[memAllocation];
            capacity = memAllocation;
            offset = 0;
        }
    }

    //Destructor
    ~MemoryArena(){
        delete[] data; 
    }

    void* allocate(size_t size) {
        if (offset + size > capacity) {   
            return nullptr;
        }
        void* ptr = static_cast<void*>(data + offset);
        offset += size;
        return ptr;
    }
};

int main(){
    MemoryArena arena(1024);

    void* mem = arena.allocate(sizeof(int));
    if (mem == nullptr) {
        std::cerr << "Allocation failed!\n";
        return 1;
    }

    int* p = static_cast<int*>(mem);
    *p = 42;
    std::cout << "Value stored: " << *p << std::endl;
    return 0;
}