#include <stdio.h> // printf
#include <stdlib.h> //exit
#include <fcntl.h> //obsluga plikow
#include <sys/types.h> 	//open
#include <sys/stat.h> 	//fork
#include <unistd.h> 	//write, read, close, open, pipe
#include <sys/wait.h>  // wait
#define PATH  "/SysOp/zad5/"
int main(int argc, char * argv[]) {
    
  int pid;
  int make;
  char *fifo;
  if(argc<2)
    {
      fifo = "myfifo";
      if((make=mkfifo(fifo, 0666))==-1)
	{
	  perror("fifo error");
	  exit(EXIT_FAILURE);	
	}
      printf("Fifo utworzone pomyslnie \n");
    }
  else
{
    printf("Korzystam z istniejacego fifo \n");
    fifo = argv[1];
}

  switch(pid=fork())
    {
    case -1:
      perror("fork error");
      exit(EXIT_FAILURE);
    case 0:
      execl("./producent.x", "producent.x", fifo, NULL);
        
    default:
      execl("./konsument.x", "konsument.x", fifo, NULL);
    
    }
  return 0;
}
   
