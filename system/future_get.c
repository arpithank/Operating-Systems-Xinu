
#include <xinu.h>

syscall future_get(future* f,int* value)
{

//	*value = *f->value;
	if(f->state == FUTURE_VALID)
	{
		f->state = FUTURE_EMPTY;
		return SYSERR;
	}

	if(f->state == FUTURE_EMPTY)
	{
		f->state = FUTURE_WAITING;
		*value = *f->value;
		f->pid = getpid();
		suspend(getpid());
		return OK;
	}

	if(f->state == FUTURE_WAITING)
	{
		f->state = FUTURE_VALID;
		return OK;
	}
}
