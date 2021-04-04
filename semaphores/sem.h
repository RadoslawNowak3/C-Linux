sem_t* semOpen(const char *nazwa); // otwieranie semafora //
sem_t* semCreate(const char *nazwa); // tworzenie semafora //
void semRemove(const char *nazwa); // usuwanie semafora //
void semP(sem_t *semafor); // opuszczanie semafora //
void semV(sem_t *semafor); // podnoszenie semafora //
int semInfo(sem_t *semafor); // informacje semafora //
int semClose(sem_t *semafor); // zamykanie semafora //
// semInit(sem_t *semafor); // inicjacja semafora //

