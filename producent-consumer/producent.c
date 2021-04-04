#include <stdio.h> // printf
#include <stdlib.h> //exit
#include <fcntl.h> //obsluga plikow
#include <sys/types.h> 	//open
#include <sys/stat.h> 	//fork
#include <unistd.h> 	//write, read, close, open, pipe
#include <sys/wait.h>  // wait
#include <time.h> // rand
#define MAX 15
int main(int argc, char * argv[])
{
	
  char buf[MAX];
  int x,y,a,b;
  char* wejscie="in.txt";
  char* fifo=argv[1];
  printf("Producent dziala \n");
  if((y=open(fifo,O_WRONLY))==-1)
    {
      perror("fifo file open error \n");
      exit(EXIT_FAILURE);
    }
  if((x=open(wejscie,O_RDONLY))==-1)
    {
      perror("input file open error \n");
      exit(EXIT_FAILURE);
    }
  printf("Producent wypisuje przekazywane dane \n");
  while((b=read(x,buf,MAX))>0) 
    {  
	sleep(1);     
      if((a=write(y,buf,b))==-1)
	{
	  perror("write error \n");
	  exit(EXIT_FAILURE);
	}
      printf("%s \n",buf);	
    }
  if(close(x)==-1)
    {
      perror("file close error \n");
      exit(EXIT_FAILURE);
    }

  if(close(y)==-1)
    {	
      perror("fifo close error \n");
      exit(EXIT_FAILURE);
    }
  printf("\nProducent konczy dzialanie \n");
  return 0;
}
