#include <xinu.h>
#include <prodcons.h>

void consumer(int count) 
{
	int ctr;
	for(ctr = 1; ctr <= global_var; ctr++)
	{
		printf("\n Consumed value  %d\n",ctr);
	}
	
}

