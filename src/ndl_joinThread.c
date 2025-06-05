#include <needle.h>

void ndl_joinThread(ndl_thread_t* addrThread)
{
    #ifdef OS_TYPE_WINDOWS

    WaitForSingleObject(addrThread->refThread,INFINITE);
    
    #elif defined(OS_TYPE_LINUX)

    pthread_join(addrThread->refThread, NULL);

    #endif
}