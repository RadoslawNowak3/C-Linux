#include <stdio.h> //printf
#include <stdlib.h> //exit
#include <unistd.h> //pause,getpid
#include <sys/types.h> //kill,getpid
#include <sys/wait.h> // obsluga sygnalu
#include <signal.h> //kill

int main(int argc, char **argv) {
  if (argc != 3)
    {
      perror("Niewłaściwa liczba argumentów. Prawidlowa inicjacja programu: make run2 [opcja] [sygnal] \n");
      exit(EXIT_FAILURE);
    }
  int pid;
  int signal = atoi(argv[2]);
  switch (pid=fork()) 
    {
    case -1: // obsluga bledu
      perror("Bład wywolania funkcji fork \n");
      exit(EXIT_FAILURE);
		
    case 0: //potomny
      execl("./obsluga.x", argv[1], argv[2], NULL);
    default: //macierzysty
      sleep(1);
      if (kill(pid, 0) != ESRCH) // sprawdzam, czy proces istnieje
	{
	  kill(pid, sygnal); //proces istnieje, wysylam sygnal
	  printf("wysłano sygnał do procesu %i.\n", pid);
	}
    }
}
return EXIT_SUCCESS;
}

