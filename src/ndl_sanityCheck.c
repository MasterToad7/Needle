#include <needle.h>
#include <stdio.h>

void ndl_sanityCheck()
{
    #ifdef OS_TYPE_WINDOWS

    printf("Needle Is Linked Properly For Windows\n");

    #elif defined(OS_TYPE_LINUX)

    printf("Needle Is Linked Properly For Linux\n");

    #endif
}