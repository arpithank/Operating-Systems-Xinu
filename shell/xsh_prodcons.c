#include <xinu.h>
#include <prodcons.h>

int global_var;

shellcmd xsh_prodcons(int32 narg, char* args[])
{
	int val = 2000;
	
	if(narg ==2 && args[1] != NULL)
		val = args[1];

	if(narg > 2)
	{
		fprintf(stderr,"\n Too many arguments passed!");
		return 1;
	}
	
	if(narg <2)
	{
		fprintf(stderr, "\n Too few arguments!");
		return 1;
	}

	resume(create(producer,1024,20,"producer",1,val));
	resume(create(consumer,1024,20,"consumer",1,val));
	
	return 0;	
	
}
