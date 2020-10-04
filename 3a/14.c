#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main()
{
	int ret,returni;
	int cd1=fork();
	int cd2;
	int cd3;
	int cd4;
	int cd5;
	char *s;
	char *ss;
	ss="./s.out";
	s="s.out";
	if(cd1<0||cd2<0||cd3<0)
	{
	perror("fork");
	exit(1);
	}
	if(cd1==0)
	{
	execl("/bin/gcc","gcc","-c","test.c",NULL);
    	}
    	else
    	{
    	waitpid(cd1, &returni, 0);
    	cd2=fork();
    	}
	if(cd2==0)
    	execl("/bin/gcc","gcc","-c","sum.c",NULL);
    	else
    	{waitpid(child2, &returni, 0);
    	cd3=fork();}
	if(cd3==0)
	execl("/bin/ar", "ar","rcs","libsum.a","sum.o", NULL);
    	else
    	{
    	waitpid(cd3, &returni, 0);
    	cd4=fork();
	}
	if(cd4==0)
	//ar rcs mylib.a sum.o
	execl("/bin/gcc","gcc","test.o","-o",s,"-static","-L.","-lsum",NULL);
	else
	{
	  waitpid(cd4, &returni, 0);
	  cd5=fork();
	}
	if(cd5==0)
	execl("./s.out", "./s.out", NULL);
    	else
    	{
    	waitpid(cd5, &returni, 0);
	}
	exit(0);
}
