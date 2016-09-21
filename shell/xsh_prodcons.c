#include <xinu.h>
#include <prodcons.h>

int global_var;

shellcmd xsh_prodcons(int32 narg, char* args[])
{
	int count = 2000;
	
	if(narg == 2 && args[1] != NULL)
	{
		count = atoi(args[1]);
	}

	if(narg > 2)
	{
		fprintf(stderr,"\n Too many arguments passed!");
		return 1;
	}
	
	if(narg < 2)
	{
		printf("\n Using default value 2000\n");
	}

	resume(create(producer,1024,20,"producer",1,count));
	resume(create(consumer,1024,20,"consumer",1,count));
	
	producer(count);
	consumer(count);
	
	return 0;	
	
}
