#define NELE 20 // Rozmiar elementu bufora
#define NBUF 5 //liczba elementów bufora
#include "pamdziel.h"
#include "sem.h"
#define MAX 200 // rozmiar tablicy
int main(int argc, char * argv[]) {
  int shmid, fd, k;
  char tab[MAX];
  printf("Z tej strony producent \n");
  //otwieranie pamieci dzielonej i semaforow //
  shmid = shmOpen(argv[2]);
  SegmentPD * buf;
  buf = (SegmentPD * ) shmMap(NULL, shmid); // odwzorowanie pamieci dzielonej //

  buf->wstaw = 0; // ustawienie wskaznika wstawienia na poczatek //
  sem_t * semProd;
  semProd = semOpen(argv[4]);
  sem_t * semKons;
  semKons = semOpen(argv[3]);

  if ((fd = open(argv[1], O_RDONLY)) == -1) { //otwieranie pliku wejsciowego //
    perror("File open error");
    exit(EXIT_FAILURE);
  }

  int counter; // ilosc wczytanych danych
  int i = 0;
  while (1) {
    semP(semProd); // opuszczam semafor producenta
    if ((counter = (read(fd, tab, NELE*sizeof(char)))) == -1) { // wczytywanie danych z pliku
      perror("Read error");
      exit(EXIT_FAILURE);
    }
    if(counter==0)
{
	break;
}
    for (k = 0; k < counter; k++) 
{
      (buf->bufor[buf->wstaw][k]) = tab[k]; //przesylka danych z tablicy do bufora cykl
      printf("%c",tab[k]); // wypisuje dane z tablicy
}
    printf("\n");
    (buf->wstaw) = (buf->wstaw+1)%NBUF; // przesuwam pozycje wstawienia
    sleep(1);
    semV(semKons); // podnosze semafor konsumenta

}
  semClose(semKons);
  semClose(semProd);
  shmClose(shmid);
  shmUnmap(buf);
  return 0;
}
