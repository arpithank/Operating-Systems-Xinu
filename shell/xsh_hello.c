/* xsh_hello.c - xsh_hello*/

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------
 * xsh_hello - print the string argument passed to it
 *------------------------------------------------------------------------
 */
shellcmd xsh_hello(int32 nargs, char *args[])
{

char welcome_string[45] = "Welcome to the world of Xinu!!";

if(nargs == 2) 
{
	//print the <string>, Welcome to the world of Xinu!!
	
	printf("Hello %s, %s\n",args[1],welcome_string);
	return 0;
}

if(nargs > 2)
{
	printf(stderr,"%s: too many arguments passed\n",args[0]);
	return 1;
}

if(nargs <2)
{
	printf(stderr, "Too few arguments!\n");
	return 1;
}
return 0;
}
