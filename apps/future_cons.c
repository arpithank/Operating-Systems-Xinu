/* Consumer values to consume*/
#include <xinu.h>

uint future_cons(future *fut) 
{
	  int i, status;
	//  for(i =0;i<10;i++)
	 // {
	  	status = future_get(fut, &i);
	  	if (status < 1) 
	  	{
			printf("future_get failed\n");
			return -1;
	  	}
	  	else
	  	{
	  		printf("it consumed %d\n", i);
	  	}
	  //}
	return OK;
}
