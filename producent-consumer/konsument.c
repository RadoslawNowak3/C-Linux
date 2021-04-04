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
  char* wyjscie="out.txt";
  char* fifo=argv[1];
  int z,v,c,d;
  printf("Konsument dziala \n");
  if((v=open(fifo,O_RDONLY,0666))==-1)
    {
      perror("fifo file open error \n");
      exit(EXIT_FAILURE);
    }
  if((z=open(wyjscie, O_WRONLY | O_CREAT | O_TRUNC,0666))==-1)
    {
      perror("output file open error \n");
      exit(EXIT_FAILURE);
    }
	  printf("Konsument wypisuje przekazywane dane \n");
  while((d=read(v,buf,MAX))>0)
    {
      if(d==-1)
      {
	perror("read error");
	exit(EXIT_FAILURE);
      }
	sleep(2); 
	printf("%s \n",buf);	
      if((c = write(z,buf,d))==-1) // zapis do pliku
	{
	  perror("write error \n");
	  exit(EXIT_FAILURE);
	}
    }
  if(close(z)==-1)
    {
      perror("file close error \n");
      exit(EXIT_FAILURE);
    }
  if(close(v)==-1)
    {
      perror("fifo close error \n");
      exit(EXIT_FAILURE);
    }
  if(unlink(argv[1])==-1)
    {
      perror("unlink error \n");
      exit(EXIT_FAILURE);
    }
  printf("\nKonsument konczy dzialanie \n");
  return 0;
}
