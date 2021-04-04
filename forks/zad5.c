#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
/* biblioteki wymagane do wykonania programu */

void wypiszID()/*wypisuje wszystkie identyfikatory procesu */
{
  printf("UID: %i, GID: %i, PID: %i, PPID: %i, PGID: %i\n", 
	getuid(), getgid(), getpid(), getppid(),getpgrp());
}

int main()
{
int i;
setpgid(0,0);
wypiszID();
  for(i=0;i<3;i++)
    {	
      switch (fork()) /*inicjuje fork */
	{
	case -1:
	
	  perror("fork error"); /* blad przy wywolywaniu forka */
	  exit(1);
	case  0:
	setpgid(0,0);	
	wypiszID();
	break;		
	default:
	wait(0);
	}
    }
  return 0;
}
