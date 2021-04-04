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
wypiszID();
  for(i=0;i<3;i++)
    {
      switch (fork()) /*inicjuje fork */
	{
	case -1:
	  perror("fork error"); /* blad przy wywolywaniu forka */
	  exit(1);
	case  0:
	wypiszID();
	sleep(1);
	break;		
	default:
	break;
	}
    }
sleep(5);
  return 0;
}
