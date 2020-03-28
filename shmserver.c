#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main()
{
	int id;
	char *ptr;
	id=shmget(3,50,IPC_CREAT|0666);
	if(id<0) {
		perror("Shmget");
		return 1;
	}
	ptr=shmat(id,NULL,0);
	printf("Enter the data\n");
	scanf("%s",ptr);
}
