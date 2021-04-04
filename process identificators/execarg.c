#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* biblioteki wymagane do wykonania programu */
#define PATH "./"
/* definiuje sciezke */
void wypiszID()
{ printf("UID: %i, GID: %i, PID: %i, PPID: %i, PGID: %i\n", /*wypisuje wszystkie identyfikatory procesu */
	 getuid(), getgid(), getpid(), getppid(),getpgrp());
}
int main(int argc, char **argv)
{
 if(argc!=2)
{
 	printf("Niepoprawna ilosc argumentow!");
	exit(1);
}
char PathName[100];
sprintf(PathName,"%s%s",PATH,argv[1]);
int i;
wypiszID();
  for(i=0;i<3;i++)
    {
      switch (fork())/*inicjuje fork */
	{
	case -1:
	  perror("fork error");/* blad przy wywolywaniu forka */
	  exit(1);
	case  0:
	execl(PathName,argv[1],NULL);
	perror("execl error");
	break;
	default:
	 if(wait(0)==-1)
	{
	 perror("wait error"); /* blad oczekiwania */
	}
	break;	
	}
    }	
  return 0;
}
