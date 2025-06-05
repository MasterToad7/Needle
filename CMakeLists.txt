cmake_minimum_required(VERSION 3.22.1)
project(needle VERSION 1.0)
project(examples-increment VERSION 1.0)

add_library(needle STATIC src/ndl_sanityCheck.c src/ndl_createThread.c src/ndl_exitThread.c src/ndl_joinThread.c)
add_executable(examples-increment examples/increment/increment.c)

target_link_libraries(examples-increment needle)

target_include_directories(needle PUBLIC include)
target_include_directories(examples-increment PUBLIC include)

set_target_properties(examples-increment PROPERTIES EXCLUDE_FROM_ALL TRUE)
