#ifndef THREAD_H
#define THREAD_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * runtineP(void * arg);
void * waitP();
void * runtineC(void * arg);
void waitC();

#endif 