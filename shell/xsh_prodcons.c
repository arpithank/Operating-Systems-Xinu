#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>
#include <stdlib.h>
int n;

shellcmd xsh_prodcons(int32 narg, char* args[])
{
	int count = 2000;
	
	//printf("\nargs[1] %s",args[1]);
	//printf("\nnumber of arg %d",narg);

	if(narg > 2)
	{
		printf("\n Too many arguments passed! Exiting...\n");
		return 1;
	}
	
	if(narg == 1)
	{
		printf("\n Using default value count 2000\n");
	}
	
	if(narg == 2 && args[1] != NULL)
        {
                count = atoi(args[1]);
                printf("\ncount set to: %d",count);
        }


	resume(create(producer,1024,20,"producer",1,count));
	resume(create(consumer,1024,20,"consumer",1,count));
	
	return 0;	
	
}
