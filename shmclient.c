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
	printf("data from file 1 : %s\n",ptr);
	scanf("%s",ptr);

}
