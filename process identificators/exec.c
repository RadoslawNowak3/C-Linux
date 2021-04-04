#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* biblioteki wymagane do wykonania programu */
void wypiszID()
{ printf("UID: %i, GID: %i, PID: %i, PPID: %i, PGID: %i\n", /*wypisuje wszystkie identyfikatory procesu */
	 getuid(), getgid(), getpid(), getppid(),getpgrp());
}
int main()
{ 
  wypiszID();
  int i;
  for(i=0;i<3;i++)
    {
      switch (fork())/*wywoluje funkcje fork*/
	{
	case -1:
	  perror("fork error");/* obsluga bledu przy wywolywaniu forka */
	  exit(1);
	case  0:
	  if(execl("./identyfikatory.x","identyfikatory.x",NULL)==-1) /* inicjuje proces, sprawdzam czy nie wystapil blad */
	    {
	      perror("execl error");/* obsluga bledu inicjacji */
	      _exit(2);
	    }	
	  break;
	default:
	  if(wait(0)==-1)/*proces macierzysty czeka na zakonczenie procesu potomnego, sprawdzam czy nie wystapil blad*/
	    {
	      perror("wait error"); /* obsluga bledu oczekiwania */
	      exit(1);
	    }
	  break;
	}
    }	
  return 0;
}
