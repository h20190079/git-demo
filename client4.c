
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main(){
int sockfd;
int len;
struct sockaddr_in address;
char buffer[1024];
int ret;

sockfd=socket(AF_INET, SOCK_STREAM, 0);
if(sockfd==-1){
perror("Client Socket Creation Error\n");
}else{
printf("Client Socket Created\n");
}

address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("127.0.0.1");
address.sin_port=htons(PORT);
len=sizeof(address);

ret=connect(sockfd,(struct sockaddr*)&address, len);
if(ret==-1){
perror("Server Connection Error\n");
}else{
printf("Server Connected\n");
}

while(1)
{
printf("Client: \t");
scanf("%s",&buffer[0]);
send(sockfd, buffer, strlen(buffer), 0);

if(strcmp(buffer,":exit")==0){
printf("Disconnecting from server");
exit(1);
}

if(recv(sockfd, buffer, 1024, 0)<0){
printf("Error in receiving data");
}else{
printf("Server: \t%s",buffer);
}
}
close(sockfd);
}
