/* File to produce value*/

#include <xinu.h>

uint future_prod(future *fut) 
{
	int i, j;
	j = (int)fut;
	printf("j = %d",j);
	for (i=0; i<10; i++) 
	{
		j+=i;
		printf("\n Value produced %d",j);
		printf("\n Calling set \n");
		future_set(fut, &j);
	}
		//calling set with the produced value
		//printf("\n Calling set \n");
	        //future_set(fut, &j);
		return OK;
}

