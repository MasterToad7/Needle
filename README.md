# Needle
Universal threading library

> **NOTE**
> Needle currently only supports Windows and Linux operating systems

## Planned Updates
- Add support for more operating systems (Mac, BSD, etc.)

# How To Compile
## Dependencies
Win32 API for Windows and PThreads for Linux. Both of which should be preinstalled under normal circumstances.

## Compile Instructions
Run the following commands
```
mkdir build
cd build
cmake ../
cmake --build .
```

## Compile Example
Run the following commands
```
mkdir build
cd build
cmake ../
cmake --build . --target examples-increment
```

## Add To CMake Project
If you would rather add Needle to a CMake project you can add the folling to your _CMakeLists.txt_.
```
add_subdirectory({PATH TO NEEDLE})
target_link_libraries(test needle)
target_include_directories(test PRIVATE {PATH TO NEEDLE}/include)
```

# Usage
## Setup
In order to start using Needle you must make sure the ```needle.h``` is included with
```
#include <needle.h>
```
Make sure needle.h is in one of your include directories.

Needle also has a designated sanity check function
```
void ndl_sanityCheck();
```
This function should print something like "Needle Is Linked Properly For {Host OS}".

## Creating And Controlling Threads
In order to create a thread you must first define a handle which will be used to refrence and control the thread.
```
ndl_thread_t example_thread;
```
Needle has a custom variable type for this called ```ndl_thread_t``` which will store a different data type depending on the host os.

In order to actually create a thread you can use the following function
```
void ndl_createThread(ndl_thread_t* addrThread, void*(*startRoutine)(void*), void* arg);
```
- _addrThread_ this argument should be a pointer to the thread handle created previously
- _startRoutine_ this argument should be the name of the function you would like the thread to fun
- _arg_ this argument should be used to pass needed arguments to the thread

Now it would probably be useful to have peace of mind of ending your thread which you can use the following function for.
```
void ndl_exitThread();
```
This function should be ran by the thread you are intending to terminate.

Needle also supports waiting until a thread is terminated to start normal operations.
```
void ndl_joinThread(ndl_thread_t* addrThread);
```
- _addrThread_ this argument should be, you guessed it, a pointer to the thread handle

For any more help you can view the examples folder to see how these functions are used in practice.