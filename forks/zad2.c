#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* biblioteki wymagane do wykonania programu */

void wypiszID()/*wypisuje wszystkie identyfikatory */
{
   printf("UID: %i, GID: %i, PID: %i, PPID: %i, PGID: %i\n", 
	getuid(), getgid(), getpid(), getppid(),getpgrp());
}

int main()
{
  wypiszID();
int i;
  for(i=0;i<3;i++)
    {
      switch (fork())/*inicjuje fork */
	{
	case -1:
	  perror("fork error");/* blad przy wywolywaniu forka */
	  exit(1);
	case  0:
	wypiszID();
	break;
	default:
	 if(wait(0)==-1)
	{
	 perror("wait error"); /* blad oczekiwania */
	}	
	}
    }	
  return 0;
}
