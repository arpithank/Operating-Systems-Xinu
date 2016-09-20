#include <xinu.h>
#include <prodcons.h>

void consumer(int count) 
{
	int ctr;
	for(ctr = global_var; ctr <= count; ctr++)
	{
		printf("\n Consumed value = %d",ctr);
	}
	
}

