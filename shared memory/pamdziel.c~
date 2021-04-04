#include "pamdziel.h"
int shmCreate(const char *nazwa){//const char *name,mode_t mode,off_t dlugosc

	int desc;
	desc=shm_open(nazwa,O_RDWR | O_CREAT | O_TRUNC,0666);
	if(desc==-1)
	{
		perror("Error creating shm\n");
		exit(EXIT_FAILURE);
	} 

	if(-1==(ftruncate(desc,sizeof(SegmentPD)))){//deskryptor_obiektu,dlugosc
		perror("Error setting size\n");
		exit(EXIT_FAILURE);
	}
	printf("Stworzono segment PD \n");
	return desc;

}
int shmOpen(const char *nazwa){
	int desc;
	desc=shm_open(nazwa,O_RDWR,0666);
	if(desc==-1){
		perror("Error opening shm\n");
		exit(EXIT_FAILURE);
	}
	printf("Otworzono istniejacy obiekt PD \n");
	return desc;
}
void shmDelete(const char *name){
	if(-1==(shm_unlink(name))){
		perror("Error deleting shm\n");
		exit(EXIT_FAILURE);
	}
	printf("Usunieto segment PD \n");
}
void shmClose(int desc)
   {
	if(-1==(close(desc))){
		perror("Error closing shm");
		exit(EXIT_FAILURE);
	}
	printf("Pomyslnie zamknieto segment PD \n");
}
void *shmMap(void *addr,int desc)
{
return mmap(NULL,sizeof(SegmentPD),PROT_READ|PROT_WRITE,MAP_SHARED,desc,0);
}
void shmUnmap(void *addr)
{
	if(munmap(addr,sizeof(SegmentPD))==-1){
		perror("Error unmapping shm \n");
		exit(EXIT_FAILURE);
	}
	printf("Usunieto odwzorowanie PD \n");
}

		

