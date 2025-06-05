#include <needle.h>

void ndl_createThread(ndl_thread_t* addrThread, void*(*startRoutine)(void*), void* arg)
{
    #ifdef OS_TYPE_WINDOWS

    DWORD threadId;
    addrThread->refThread = CreateThread(NULL,0,startRoutine,arg,0,&threadId);

    #elif defined(OS_TYPE_LINUX)

    pthread_create(&addrThread->refThread, NULL, startRoutine, arg);

    #endif
}