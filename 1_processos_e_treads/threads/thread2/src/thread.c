#include "thread.h"
#include<pthread.h>

void * routineP(void * arg){
    int data[10] = {34, 5, 28, 98, 56, 11, 62, 33, 89, 100};
    int index = * (int *)arg;

    printf("Index: %d Value: %d \n", index, data[index]);

    pthread_exit(arg);
}

void * waitP(){
    pthread_t th[10];

    for(int i=0; i<10; i++){
        if(pthread_create(&th[i], NULL, &routineP, &i) != 0){
            perror("Failed to create thread");
        }
    }

    for(int i=0; i<10; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("Failed to join threads");
        }
    }

    pthread_exit(NULL);

}

void * routineC(void * arg){
    int data[10] = {34, 5, 28, 98, 56, 11, 62, 33, 89, 100};
    int index = * (int *)arg;

    printf("Index: %d Value: %d \n", index, data[index]);

    pthread_exit(arg);
}

void waitC(){
    pthread_t th[10];

    for(int i=0; i<10; i++){
        int *a = (int*) malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i], NULL, &routineP, &i) != 0){
            perror("Failed to create thread");
        }
    }

    for(int i=0; i<10; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("Failed to join threads");
        }
    }
}