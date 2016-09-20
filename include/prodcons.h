/*producer consumer header file*/

#include<stdio.h>
#include<xinu.h>
#include<stdlib.h>

extern int global_var;

void consumer(int count);
void producer(int count);
