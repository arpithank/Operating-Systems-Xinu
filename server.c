#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

int main()
{

	int socketfd,nbytes, from_len;
	int portno = 3002;
	struct sockaddr_in server_addr, from_addr;
	char buff[512];
	char reply[512] ;
	int len;

	socketfd = socket(AF_INET,SOCK_DGRAM,0 );
	if (socketfd < 0)
		printf(" Error:socketfd");

	server_addr.sin_family = AF_INET;
     	server_addr.sin_addr.s_addr = INADDR_ANY;
     	server_addr.sin_port = htons(portno);

	if(bind(socketfd, (struct sockaddr*)&server_addr,sizeof(server_addr)) < 0)
		printf(" Error:socketfd");
	
	from_len = sizeof(from_addr);
	printf("Server called: \n");
	while(1)
	{
		bzero(buff,512);
		printf("Server Running.\n");		
		nbytes = recvfrom(socketfd, buff, sizeof(buff), 0, (struct sockaddr*)&from_addr, &from_len);
		if (nbytes < 0 )
		{
			printf("Error:recvfrom");
		}			
		printf("Message: %s\n",buff);
		len = strlen(buff);
		snprintf(reply,sizeof(reply),"%d",len);

		sendto(socketfd, reply, strlen(reply), 0,(struct sockaddr*)&from_addr,from_len);
		memset(buff,'\0',sizeof(buff));

		printf("Response sent!\n");
	}

	
	return 0;
}
