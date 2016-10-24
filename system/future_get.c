
#include <xinu.h>

syscall future_get(future* f,int* value)
{
	//To hold the value of the pid of the process
	pid32 currpid;

	if(f->flag == FUTURE_EXCLUSIVE)
	{
		if(f->state == FUTURE_VALID)
		{
			*value = *(f->value);
			f->state = FUTURE_EMPTY;
			return OK;
		}

		if(f->state == FUTURE_EMPTY)
		{
			//printf("\n Suspending process %d ",getpid());
			f->state = FUTURE_WAITING;
			f->pid = getpid();
			suspend(getpid());
			*value = *(f->value);
			f->state = FUTURE_EMPTY;
			return OK;
		}

		else
		{ return SYSERR;}

	}
	
	else if(f->flag == FUTURE_SHARED)
	{
		if(f->state == FUTURE_VALID)
                {
                        *value = *(f->value);
                        f->state = FUTURE_EMPTY;
                        return OK;
                }
		
		if(f->state == FUTURE_EMPTY || f->state == FUTURE_WAITING)
                {
			//printf("\n Suspending process %d ",getpid());
			f->state = FUTURE_WAITING;
			currpid = getpid();
			
			//Add pid to the queue
			
			en_queue(&f->get_queue,currpid);
			suspend(currpid);
			*value = *(f->value);
			f->state = FUTURE_EMPTY;
                        return OK;

		}
		
	}
	
	else if(f->flag == FUTURE_QUEUE)
	{
		if(f->set_queue.count > 0)
		{
			//Remove the pid from the queue
			currpid = de_queue(&f->set_queue);
			//printf("\n Resuming process %d",currpid);
			resume(currpid);
			*value = *(f->value);
		}
		else
		{
			en_queue(&f->get_queue,getpid());
			//printf("\n Suspending  process %d",getpid());
			suspend(getpid());
			*value = *(f->value);
		}
		return OK;
	}
	
}
