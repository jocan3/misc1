#include <pthread.h>
#include <stdio.h>

void* threadRun (void* args) {
    printf("Hello world from secondary thread\n");
    return NULL;
}

int main(void) {

    pthread_t thread;
    pthread_create(&thread, NULL, threadRun, NULL);
    printf("Hello world from main thread\n");

    pthread_join(thread, NULL);

    return 0;
}