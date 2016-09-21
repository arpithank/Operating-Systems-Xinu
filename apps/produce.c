//producer code for producing a value

#include <xinu.h>
#include <prodcons.h>

void producer(int count) 
{
	int ctr;
	
	for(ctr = 1; ctr <= count; ctr++)
	{
		printf("\n Produced value %d\n",ctr);
		global_var = ctr;
	}
}



