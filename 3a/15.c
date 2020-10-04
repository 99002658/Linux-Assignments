#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main(int argc,char *argv[])
{
int i;int ret,returni;
	if(argc==1)
	{
	printf("no Commands to execute\n");return 1;
	}
	size_t size=1;
	for(i=1;i<argc;i++)
	size+=strlen(argv[i])+1;
	char *s=malloc(size);
	for(i=1;i<argc;i++)
	{
	strcat(s,argv[i]);
	strcat(s," ");
	}
	//printf("Enter the command: \n");
	//int i;
	//scanf(" %[^\n]s\n",s);
	ret=fork();
	if(ret==0)
	{
    	execl("/bin/sh","sh","-c",s,NULL) ;
	}
	else
	{
		waitpid(ret, &returni, 0);
	}
	exit(0);
}
