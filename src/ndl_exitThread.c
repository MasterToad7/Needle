#include <needle.h>

void ndl_exitThread()
{
    #ifdef OS_TYPE_WINDOWS

    ExitThread(NULL);

    #elif OS_TYPE_LINUX

    pthread_exit(NULL);

    #endif
}