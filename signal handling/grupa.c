#include <stdio.h> //printf
#include <stdlib.h> //exit
#include <unistd.h> //pause,getpid
#include <sys/types.h> //kill,getpid
#include <sys/wait.h> // obsluga sygnalu
#include <signal.h> //kill

int main(int argc, char **argv) {
int pid;
int i;
int pid2;
switch(pid=fork())
{
 case -1: // obsluga bledu
      perror("Bład wywolania funkcji fork \n");
      exit(EXIT_FAILURE);
 case 0: //potomny
 setpgid(0,0);
for(i=0;i<3;i++)
{
      execl("./obsluga.x", argv[1], argv[2], NULL);
}
pid2 = getpgid(pid);
default:

if (kill(pid2, 0) != ESRCH) // sprawdzam, czy grupa procesow istnieje
	{
	  kill(pid2, sygnal); //proces istnieje, wysylam sygnal
	  printf("wysłano sygnał do procesu %i.\n", pid);
	}
    

}
}
