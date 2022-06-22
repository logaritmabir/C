#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <stdlib.h>

#define THREAD_NUM 10

int buffer[10];
int count = 0;

void *consumer(void *param);
void *producer(void *param);

pthread_mutex_t mutexBuffer;
sem_t semFull;
sem_t semEmpty;

int main(int argc,char *argv[]){
    int i;
    pthread_t threads[THREAD_NUM];
    pthread_mutex_init(&mutexBuffer,NULL);
    sem_init(&semFull,0,0);
    sem_init(&semEmpty,0,10);
    for(i=0;i<THREAD_NUM;i++){
        if(i%2 == 0){
            pthread_create(&threads[i],NULL,producer,NULL);
        }
        else{
            pthread_create(&threads[i],NULL,consumer,NULL);
        }
    }

    for(i=0;i<THREAD_NUM;i++){
        if(pthread_join(threads[i],NULL) != 0){
            printf("Joining Error Occured.");
        }
    }
}

void *producer(void *param){
    while(1){
        int randomNumber = rand() % 10;

        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        
        buffer[count] = randomNumber;
        count++;
        
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
        printf("Added number is : %d\n",randomNumber);
    }
}

void *consumer(void *param){
    while(1){
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);

        int consumeNumber = buffer[count];
        count--;
        
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semEmpty);
        printf("Taken number is : %d\n",consumeNumber);
    }
}