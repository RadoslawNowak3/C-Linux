#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
  const int bufor_size = 150;
  char bufor[bufor_size];
  int i,pid;
  int fd[2];
  if(pipe(fd)==-1)
    {
      perror("pipe error");
      exit(1);
    }

  switch(pid=fork())
    {
    case -1:
      perror("fork error");
      exit(1);
    case 0: //producent
      close(fd[0]);	
      if((i=open("wejscie.txt", O_RDONLY))==-1)
	{ 
	  perror("open error");
	  exit(4);
	}
      printf("z tej strony producent \n");	
      printf("pobieram surowce z pliku wejscie.txt i wstawiam je do potoku \n");
      int x;
      if((x=read(i, bufor, bufor_size))==-1)
	{
	  perror("read error");
	  exit(1);
	}
      if(close(i)==-1)
	{
	  perror("close error");
	  exit(2);
	}
      close(fd[1]);
    default: //konsument
     close (fd[1]);     	
      if((i=open("wyjscie.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600))==-1)
	{
	  perror("open error");
	  exit(4);
	}
      printf("z tej strony konsument \n");
      printf("pobieram towar z potoku i umieszczam go w pliku wyjscie.txt \n");
      int z;
      if((z=write(i, bufor, bufor_size))==-1)
	{
	  perror("write error");
	  exit(5);
	}
      if(close(i)==-1)
	{
	  perror("close error");
	  exit(6);
	}
     close(fd[0]);	
    }
  return 0;
}
