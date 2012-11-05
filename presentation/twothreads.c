
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int global_i = 0;

void *thread(void *data)
{
    for (;;) {
        printf("now %p is %d\n", data, ++global_i);
        sleep(1);
    }

    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t t1, t2;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&t1, &attr, thread, (void *)1);
    pthread_create(&t2, &attr, thread, (void *)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
