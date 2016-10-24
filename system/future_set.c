
#include <xinu.h>

syscall future_set(future *f, int *value)
{
	pid32 currpid;
	if(f->flag == FUTURE_QUEUE)
	{
		if(f->get_queue.count > 0)
		{
			*(f->value) = *value;
			currpid = de_queue(&f->get_queue);
			resume(currpid);
		}
		else
		{
			en_queue(&f->set_queue,getpid());
			suspend(getpid());
			*(f->value) = *value;
		}
		return OK;
	}
	
	if(f->state == FUTURE_EMPTY)
	{
		f->state = FUTURE_VALID;
		*(f->value) = *value;
		//resume(f->pid);
		return OK;
	}
	
	if(f->state == FUTURE_WAITING)
	{
		printf("\n Resuming process %d ",f->pid);
		*(f->value) = *value;
		f->state = FUTURE_VALID;
		
		if(f->flag == FUTURE_SHARED)
		{
			currpid = de_queue(&f->get_queue);
			while(currpid != SYSERR)
			{
				resume(currpid);
			}
		}
		
		else if(f->flag == FUTURE_QUEUE)
		{
			currpid = de_queue(&f->get_queue);
			resume(currpid);
		}
		else
		{
			resume(f->pid);
		}
	}
	else
	{
		return SYSERR;
	}

}
