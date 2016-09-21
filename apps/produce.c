//producer code for producing a value

#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>

void producer(int count) 
{
	int ctr;
	for(ctr = 0; ctr <= count; ctr++)
	{
		global_var = ctr;
		printf("\n value produced %d",global_var);
	}
}



