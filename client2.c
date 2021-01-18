#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{

	int sockfd;
	int len;
	int result;
	struct sockaddr_in address;

	sockfd=socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=9734;
	len=sizeof(address);

	result= connect(sockfd, (struct sockaddr*)&address, len);

	if(result==-1)
	{
	perror("oops: client1");
	}

	char ch='A';

	write(sockfd,&ch,1);
	read(sockfd,&ch,1);
	printf("received from server: %c",ch);
	close(sockfd);



}
