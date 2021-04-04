#ifndef sem_h
#define sem_h
#include <stdio.h>
#include <errno.h>
#include <string.h> // string //
#include <stdlib.h>
#include <semaphore.h> // biblioteka z semaforami //
#include <unistd.h> // fork //
#include <sys/types.h> // pid //
#include <sys/wait.h> // wait //
#include <sys/stat.h> // o_creat //
#include <fcntl.h> // o_creat //
sem_t* semOpen(const char *nazwa);
sem_t* semCreate(const char *nazwa);
void semRemove(const char *nazwa);
void semP(sem_t *semafor);
void semV(sem_t *semafor);
int semInfo(sem_t *semafor);
int semClose(sem_t *semafor);
// semInit(sem_t *semafor);
#endif
