#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    printf("pid: %d\n", getpid());

    for (i=0;i<5;);

    printf("woho\n");

    return 0;
}

