/*Consumer code to consume values*/

#include <xinu.h>
#include <prodcons.h>

void consumer(int count)
{
int ctr;
printf("\n Consumed Value %d ",n);
for(ctr =1; ctr<= count; ctr++)
{
	printf("\n Consumed value %d ",ctr);
}
}
