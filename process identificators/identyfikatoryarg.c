#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char **argv)
{
 printf("UID: %i, GID: %i, PID: %i, PPID: %i, PGID: %i\n", /*wypisuje wszystkie identyfikatory procesu */
	getuid(), getgid(), getpid(), getppid(),getpgrp());
}
