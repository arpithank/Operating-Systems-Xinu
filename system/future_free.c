#include <stdio.h>
#include <future.h>

syscall future_free(future* f)
{
	printf("\n Free memory assigned to future object");
	if(freemem(f,sizeof(f)) == OK )
		return OK;
	else
		retun SYSERR;
}
