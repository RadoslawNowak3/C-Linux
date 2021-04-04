#include <stdio.h> //printf
#include <stdlib.h> //exit
#include <unistd.h> //pause,getpid
#include <sys/types.h> //kill,getpid
#include <sys/wait.h> // obsluga sygnalu
#include <signal.h> //kill

void my_sighandler(int signal) // funkcja uzytkownika obslugujaca sygnaly
{
  printf("Poprawnie przechwycono sygnał %d \n", signal);
}

int main(int argc, char **argv) {

  extern const char * const sys_siglist[]
    if (argc <3)
      {
        perror("Niewłaściwa liczba argumentów. Prawidlowa inicjacja programu: make run1 opcja] [sygnal] \n");
        exit(EXIT_FAILURE);
      }
  int pid;
  int sygnal = atoi(argv[2]);
  switch (*argv[1])
    {
    case 'p':
      if (signal(sys_siglist[sygnal], my_sighandler) == SIG_ERR) // przechwytuje sygnal i obsluguje za pomoca funkcji my_sighandler
	{
	  perror("Wystąpił bląd przechwytywania i obslugi sygnalu");
	  exit(EXIT_FAILURE);
	}
      break;
    case 'd':
      if (signal(sys_siglist[sygnal], SIG_DFL) == SIG_ERR) // domyslna obsluga sygnalu
	{
	  perror("Wystąpił bląd domyślnej obslugi sygnalu");
	  exit(EXIT_FAILURE);
	}
      break;
    case 'i':
      if (signal(sys_siglist[sygnal], SIG_IGN) == SIG_ERR) // ignorowanie sygnalu
	{
	  perror("Wystąpił bląd ignorowania sygnalu");
	  exit(EXIT_FAILURE);
	}
      break;
    default:
      printf("Podana opcja nie istnieje. Możliwe opcje: 'p'- przechwytywanie i obsluga sygnalu, 'd' - domyslna obsluga sygnalu,'i' - ignorowanie sygnalu \n");
    } 
  pause();
  pid = getpid();
  printf("Zakończono proces obslugi o pid = %i \n", pid);
 
  return 0;
}

