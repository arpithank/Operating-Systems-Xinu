/* File to produce value*/

#include <xinu.h>
#include <stdlib.h>

uint future_prod(future *fut) 
{
	int i;
	i=rand();
	
	//printf("j = %d",j);
//	for (i=0; i<10; i++) 
//	{
		
		printf("\n Value produced %d\n",i);
		//printf("\n Calling set \n");
		future_set(fut, &i);
//	}
		
		return OK;
}

