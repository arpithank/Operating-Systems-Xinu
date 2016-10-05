/* Allocate memory for the future object*/

#include <stdio.h>
#include <future.h>

future* future_alloc(int future_flag)
{
	future* f_obj;
		
	f_obj = getmem(sizeof(f_obj));
	printf("\n Block of memory assigned %d",&f_obj);
	f_obj->flag = future_flag;

	return f_obj;

}

