#include <stdio.h> // printf
#include <stdlib.h> //exit
#include <fcntl.h> //obsluga plikow
#include <sys/types.h> 	//open
#include <sys/stat.h> 	//fork
#include <unistd.h> 	//write, read, close, open, pipe
#include <sys/wait.h>  // wait
#include <time.h> // rand
#define MAX 15
/* int plikIstnieje (const char* fileName)
{
    FILE* plik;
    plik = fopen(fileName, "r");
    if (plik!=NULL)
    {
        fclose(plik);
        return 1;
    }
    fclose(plik);
    return 0;
}
*/
void potomny(int fd[] , char *filename)
{
	char buf[MAX];
	int x;
	printf("Z tej strony proces potomny\n");
	if((close(fd[0]))==-1)
	{
		perror("pipe close error \n");
		exit(EXIT_FAILURE);
	}
	if((x=open(filename,O_RDONLY))==-1)
	{
		perror("file open error \n");
		exit(EXIT_FAILURE);
	}
	printf("Rozpoczynam odczyt danych z pliku i zapis do potoku\n");
	while(read(x,buf,MAX)>0) 
{
	int a; 
	if((a=write(fd[1],buf,MAX))==-1)
	{
		perror("write error \n");
		exit(EXIT_FAILURE);
	}
	sleep(1);	
	printf("%s",buf); // wypisuje przekazywane dane na ekran
}
	if(close(x)==-1)
	{
		perror("file close error \n");
		exit(EXIT_FAILURE);
	}

	if(close(fd[1])==-1)
	{	
		perror("Blad zamkniecia \n");
		exit(EXIT_FAILURE);
	}
	printf("\nKoniec dzialania procesu potomnego\n");
 	wait(NULL);
}

void macierzysty(int fd[] , char *filename2)
{
	char buf[MAX];
	int z;
	printf("Z tej strony proces macierzysty \n");
	if(close(fd[1])==-1)
	{
		perror("pipe close error \n");
		exit(EXIT_FAILURE);
	}
	if((z=open(filename2,O_WRONLY | O_CREAT | O_TRUNC,0666))==-1)
	{
		perror("file open error \n");
		exit(EXIT_FAILURE);
	}
	printf("Rozpoczynam odczyt z potoku i zapis do pliku \n");
	while(read(fd[0],buf,MAX)>0)
	{
	int c = write(z,buf,MAX); // zapis do pliku
	if(c<0)
	{
		perror("Blad zapisu \n");
		exit(EXIT_FAILURE);
	}
	sleep(1);
	printf("%s",buf); // wypisuje przekazywane dane na ekran
	}
	if(close(z)==-1)
	{
		perror("file close error \n");
		exit(EXIT_FAILURE);
	}
	if(close(fd[0])==-1)
	{
		perror("pipe close error \n");
		exit(EXIT_FAILURE);
	}
	printf("\nKoniec dzialania procesu macierzystego \n");
}
	
int main(int argc, char *argv[])
{
	if(argc<3)
	{
		printf("Niepoprawna liczba argumentow\n");
		printf("Przyklad wywolania \n");
		printf("./potok.x wejscie.txt wyjscie.txt \n");
		exit(EXIT_FAILURE);
	}
	// srand(time(NULL));
	// int p=rand()%5+1;
	/*if (plikIstnieje(argv[1])==0)
	{
	 printf("Podany plik wejsciowy nie istnieje, prosze podac poprawna nazwe \n");
	exit(EXIT_FAILURE);
	}
        */
        int filedes[2];
	if(pipe(filedes) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	printf("Powstal potok \n");

	int pid;

	switch(pid=fork())
{
 	case -1:
	perror("fork error");
	exit(EXIT_FAILURE);
	case 0:
	potomny(filedes,argv[1]);
	break;
	default:
	wait(NULL);
	sleep(1);
	macierzysty(filedes,argv[2]);
	printf("\nDane przekazane pomyslnie\n");
}

return 0;
};
