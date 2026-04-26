cmake_minimum_required(VERSION 3.16)
project(AuraDB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files
add_executable(auradb src/allocate.cpp)
