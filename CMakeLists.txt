cmake_minimum_required(VERSION 4.3)
project(DSLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(List-Test test/List.cpp)
add_executable(ForwardList-Test test/ForwardList.cpp)
add_executable(Vector-Test test/Vector.cpp)
add_executable(Deque-Test test/Deque.cpp)
add_executable(Stack-Test test/Stack.cpp)
add_executable(Queue-Test test/Queue.cpp)