#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
// Generate a unique key using ftok
key_t key = ftok("shmfile", 65);
// Get an identifier for the shared memory segment using shmget
int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
printf("Shared memory id = %d \n",shmid);
// Attach to the shared memory segment using shmat
char* str = (char*)shmat(shmid, (void*)0, 0);
printf("Write Data : ");
fgets(str, 1024, stdin);
printf("Data written in memory: %s\n", str);
// Detach from the shared memory segment using shmdt
shmdt(str);
return 0;
}
