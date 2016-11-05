/* File to produce value*/

#include <xinu.h>
#include <stdlib.h>

uint future_prod(future *fut) 
{
	int i=0;
	
	i = rand();
	future_set(fut, &i);
	printf("\n Value produced %d\n",i);
		
	return OK;
}

