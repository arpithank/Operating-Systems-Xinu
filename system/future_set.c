
#include <xinu.h>

syscall future_set(future *f, int *value)
{
//	f->value = *value;
	if(f->state == FUTURE_EMPTY)
	{
		f->state = FUTURE_VALID;
		*f->value = *value;
		resume(f->pid);
		return OK;
	}

	if(f->state == FUTURE_VALID)
	{
		return SYSERR;
	}

	if(f->state == FUTURE_WAITING)
	{
		f->state = FUTURE_VALID;
		return OK;
	}
}
