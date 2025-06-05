#include <needle.h>
#include <stdio.h>

void* increment(void* value)
{
    *(int *)value += 1;
    printf("New value is %d\n", *(int *)value);

    ndl_exitThread();

    printf("If you are seeing this exit doesn't work\n");
}

int main()
{
    ndl_sanityCheck();

    ndl_thread_t thread1;

    int value;
    printf("Type a number >");
    scanf("%d",&value);
    printf("Remember you choose %d\n", value);

    ndl_createThread(&thread1, increment, &value);

    printf("Should happen before increment\n");

    ndl_joinThread(&thread1);

    printf("Should happen after increment\n");

    return 0;
}