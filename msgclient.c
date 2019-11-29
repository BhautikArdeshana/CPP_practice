#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
struct msgbuf{
	long mtype;
	char text[10];
};

int main()
{
	int id;
	struct msgbuf mp;
//	mp.mtype=2;
//	strcpy(mp.text,"Hello");
	id = msgget(3,IPC_CREAT|0666);
	if(id<0){
		perror("MSGGET");
	}
	perror("MSGGET");
	printf(" id= %d\n",id);
	msgrcv(id,&mp,sizeof(mp),2,0);
	printf("%s",mp.text);
}
