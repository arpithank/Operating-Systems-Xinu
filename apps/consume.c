/*Consumer code to consume values*/

#include <xinu.h>
#include <prodcons.h>

void consumer(int count)
{
	int ctr;
	
	for(ctr =0; ctr<= count; ctr++)
	{
		printf("\n Consumed value %d ",n);
	}
	printf("\n");
}
