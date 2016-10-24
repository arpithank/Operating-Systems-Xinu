#include<xinu.h>

#define QUEUE_LENGTH 50

void init_queue(queue* Q)
{
	
	Q->front = 0;
	Q->rear = -1;
	Q->count = 0;
	Q->data = (int*)getmem(QUEUE_LENGTH);
}

int en_queue(queue* Q,int x)
{
	if(Q->rear == QUEUE_LENGTH)
	{
		printf("Queue too full to insert");
		return SYSERR;
	}
	else
	{
		Q->data[++Q->rear] = x;
		Q->count = Q->count+1;
		return OK;
	}
}

int de_queue(queue* Q)
{
	int item;
	if(Q->count< 0)
	{
		printf("\n -All items dequeued-");
		return SYSERR;
	}
	
	else
	{
		item = Q->data[Q->front];
		Q->front = Q->front +1;
		Q->count = Q->count -1;
		return item;	
	}
	
}
