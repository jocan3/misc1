#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* threadRun (void* args) {
    printf("Hello world from thread %zu\n", (size_t)args);
    return NULL;
}

int main(int argc, char* arg[]) {

    // arg[0] = command name
    // arg[1] = number of threads

    size_t thread_count = 0;

    if (argc >= 2) {
        thread_count = (size_t)strtoul(arg[1], NULL, 10);
    } else {
        fprintf(stderr, "error. Invalid number of parameters.\n");
        return 1;
    }

    pthread_t* threads = malloc((size_t)(thread_count * sizeof(pthread_t)));
    
    for (size_t i = 0; i < thread_count; ++i) {
        pthread_create(&threads[i], NULL, threadRun, (void*)i);
    }
    
    printf("Hello world from main thread\n");


    for (size_t i = 0; i < thread_count; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}