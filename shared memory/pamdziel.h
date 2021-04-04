#ifndef PAMDZIEL_H
#define PAMDZIEL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define NELE 20
#define NBUF 5
int shmCreate(const char *nazwa);//const char *nazwa, mode_t mode,off_t dlugosc
int shmOpen(const char *nazwa);//const char *nazwa, mode_t mode
void shmDelete(const char *nazwa);
void shmClose(int desc);	
void *shmMap(void *addr,int desc);
void shmUnmap(void *addr);//void *addr , size_t length
typedef struct 
{
	char bufor[NBUF][NELE]; //wspolny bufor danych
	int wstaw,wyjmij; //Pozycje wstawiania i wyjmowania bufora
} SegmentPD;
#endif
