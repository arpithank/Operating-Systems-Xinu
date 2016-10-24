#include <xinu.h>

syscall future_free(future* f)
{
	printf("\n Free memory assigned to future object");
	if(freemem(f,sizeof(future)) == OK )
		return OK;
	else
		return SYSERR;
}
