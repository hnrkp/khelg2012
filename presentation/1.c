#include <stdio.h>

static int i = 0;

struct foo { int i; long b; char *c; union { int a; int c; } fnord; };

struct foo foo;

static void harmless_function(void)
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("hello gdb! my i is %i\n", i);
        foo.fnord.c = i;
}

static void crashing_function(void)
{
    if (i < 1)
        *((int*)0) = 0;
}

int main(int argc, char **argv)
{
    int i;

    harmless_function();

    for (i = 5; i < 100; ++i)
        crashing_function();

    return 0;
}

