#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>
#include <stdlib.h>
#include <future.h>
int n;
sid32 produced, consumed;

shellcmd xsh_prodcons(int32 narg, char* args[])
{
	int count = 2000;
	future *f1, *f2, *f3;

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
	produced = semcreate(0);
	consumed = semcreate(1);

	f1 = future_alloc(FUTURE_EXCLUSIVE);
	f2 = future_alloc(FUTURE_EXCLUSIVE);
	f3 = future_alloc(FUTURE_EXCLUSIVE);
	       
	resume( create(future_cons, 1024, 20, "fcons1", 1, f1);
	resume( create(future_prod, 1024, 20, "fprod1", 1, f1) );
	resume( create(future_cons, 1024, 20, "fcons2", 1, f2) );
	resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );
	resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );
	resume( create(future_prod, 1024, 20, "fprod3", 1, f3) );
	resume(create(producer,1024,20,"producer",1,count));
	resume(create(consumer,1024,20,"consumer",1,count));
	
	return 0;	
	
}
