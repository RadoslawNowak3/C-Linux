#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
/* biblioteki wymagane do wykonania programu */
int main()
{
  printf("UID: %i, GID: %i, PID: %i, PPID: %i, PGID: %i\n", /*wypisuje wszystkie identyfikatory procesu */
	 getuid(), getgid(), getpid(), getppid(),getpgrp());
  return 0;
}

