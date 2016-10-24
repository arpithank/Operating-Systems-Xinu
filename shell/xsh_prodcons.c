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
	produced = semcreate(0);               
	consumed = semcreate(1);

	if(narg == 2)
	{
		//Using futures
		if(strncmp(args[1],"-f",strlen(args[1]))==0)
		{
			printf("\n Using futures");
			f1 = future_alloc(FUTURE_EXCLUSIVE);
			f2 = future_alloc(FUTURE_EXCLUSIVE);
			f3 = future_alloc(FUTURE_EXCLUSIVE);

			resume( create(future_cons, 1024, 20, "fcons1", 1, f1));
			resume( create(future_prod, 1024, 20, "fprod1", 1, f1) );
			resume( create(future_cons, 1024, 20, "fcons2", 1, f2) );
			resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );
			resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );
			resume( create(future_prod, 1024, 20, "fprod3", 1, f3) );
			resume(create(producer,1024,20,"producer",1,count));
			resume(create(consumer,1024,20,"consumer",1,count));
	
			return 0;

		}
		//Using shared futures
		else if(strncmp(args[1],"-fs",strlen(args[1]))==0 )
		{	
			printf("\n Using shared futures");
			f1 = future_alloc(FUTURE_SHARED);
			resume( create(future_cons, 1024, 20, "fcons2", 1, f1));
                        resume( create(future_cons, 1024, 20, "fcons3", 1, f1) );
                        resume( create(future_cons, 1024, 20, "fcons4", 1, f1) );
                        resume( create(future_cons, 1024, 20, "fprod5", 1, f1) );
                        resume( create(future_prod, 1024, 20, "fprod2", 1, f1) );
			
			return 0;			

		}
		//Using queue future
		else if(strncmp(args[1],"-fq",strlen(args[1]))==0 )
		{
			printf("\n Using queue future");
			f1 = future_alloc(FUTURE_QUEUE);
			
			resume( create(future_cons, 1024, 20, "fcons6", 1, f1));
                        resume( create(future_cons, 1024, 20, "fcons7", 1, f1) );
                        resume( create(future_cons, 1024, 20, "fcons7", 1, f1) );
                        resume( create(future_cons, 1024, 20, "fcons7", 1, f1) );
                        resume( create(future_prod, 1024, 20, "fprod3", 1, f1) );
                        resume( create(future_prod, 1024, 20, "fprod4", 1, f1) );
			resume( create(future_prod, 1024, 20, "fprod5", 1, f1) );
                        resume( create(future_prod, 1024, 20, "fprod6", 1, f1) );

		}
		
		else
                {
                        count = atoi(args[1]);
                        printf("\nCount set to: %d",count);
                        //produced = semcreate(0);
                        //consumed = semcreate(1);
                        resume( create(produced, 1024, 20, "producer", 1, count) );
                        resume( create(consumed, 1024, 20, "consumer", 1, count) );

                        return 0;
                }


		if(narg > 2)
		{
			printf("\n Too many arguments passed! Exiting...\n");
			return 1;
		}
	
		if(narg == 1)
		{
			printf("\n Using default value count 2000\n");
		}
	
	}
	
	return 0;	
	
}
