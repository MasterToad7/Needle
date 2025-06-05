#ifndef NEEDLE_H
#define NEEDLE_H

#ifdef _WIN32
    #include <Windows.h>
    #define OS_TYPE_WINDOWS
#elif __linux__
    #include <pthreads.h>
    #define OS_TYPE_LINUX
#else
    #error "OS not detected, Needle only supports Windows and Linux for the time being."
#endif

typedef struct ndl_thread
{
    #ifdef OS_TYPE_WINDOWS

    HANDLE refThread;

    #elif OS_TYPE_LINUX

    pThread_t refThread;

    #endif
} ndl_thread_t;

// Preform a sanity check to make sure Needle is linked properly
void ndl_sanityCheck();

// Create a new thread
void ndl_createThread(ndl_thread_t* addrThread, void*(*startRoutine)(void*), void* arg);

// Exit the current thread
void ndl_exitThread();

// Wait for another thread to finish
void ndl_joinThread(ndl_thread_t* addrThread);

#endif