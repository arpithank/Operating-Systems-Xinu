/*Producer code to produce values*/

#include <xinu.h>
#include <prodcons.h>

void producer(int count)
{
	int ctr;

	for(ctr =0; ctr< count;ctr++)
	{
		printf("\n Value produced %d ",ctr);
		n++;
	}
}
