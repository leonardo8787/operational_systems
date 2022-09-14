#ifndef THREAD_H
#define THREAD_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * soma(void *arg);
void * wait(void *arg);

#endif 