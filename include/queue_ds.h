// Data Structure to maintain the queue

typedef struct queue_ds
{
	int rear;
	int front;
	int *data;
	int count;
	
}queue;

void init_queue(queue* Q);
int en_queue(queue* Q,int x);
int de_queue(queue* Q);

