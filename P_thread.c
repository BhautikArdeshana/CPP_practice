#include <stdio.h>
#include <pthread.h>
void thread_1(int i){

	//int i=10;
	while(i-->0){
	printf("Hello from thread_1\n");
	}
}

int main()
{
	pthread_t t;
	char *p;
	pthread_create(&t,NULL,thread_1,20);
	printf("Hello from Main()\n");
	pthread_join(t,&p);
}
