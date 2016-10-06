/* Allocate memory for the future object*/

#include <xinu.h>

future* future_alloc(int future_flag)
{
	future* f_obj;
		
	f_obj = (future*)getmem(sizeof(future));
	if(f_obj)
	{
	
		printf("\n Block of memory assigned %d",&f_obj);
		/* do a getmem for the value that is part of struct */ 
		f_obj->value = (int*)getmem(sizeof(int));
		/* Assign flag value */
		f_obj->flag = future_flag;
		f_obj->state = FUTURE_EMPTY;
		
		return f_obj;
	}
	return NULL;

}

