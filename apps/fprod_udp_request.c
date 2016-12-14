#include "future.h"

int fprod_udp_request(future *fut,int serverip,int portno,int locport)
{
	char buffer[512];
	char message[512];
	int retval,msg_len,slot;
	int value,status;
	memset(message,'\0',sizeof(message));
	getchar();
	// add new slot
	slot = udp_register(serverip, portno, locport);
	if (slot == SYSERR) 	
	{
		printf(" Error while calling udp register %d ",locport);
		return -1;
	}
	while(1)
	{
		while(fut->state==FUTURE_VALID)
			printf("");

		printf("\n>");
		msg_len = strlen(message);
		message[msg_len-1]='\0';
		retval = udp_send(slot, message, msg_len);
		if(retval == SYSERR)
		{
			printf(" Error in udp sending datagram ");
			return -1;
		}
	
		retval = udp_recv(slot, buffer, sizeof(buffer),3000);
		if(retval == SYSERR)
		{ 	
			printf("Error in receiving datagram");
			return -1;
		}
		if(retval == TIMEOUT)
		{
			printf("Timeout in receiving datagram");
			return -1;
		}
		value = atoi(buffer);
  		if (status < 1)
  		{
    			printf("future_set failed\n");
    			return -1;
 		}
		if(value==-1)
			break;
		memset(buffer,'\0',sizeof(buffer));
	}
	udp_release(slot);
	return 0;
}