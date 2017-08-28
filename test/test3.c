#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


//global
int x=0;

void *func(void *);
int main(){
	//global
	pthread_t t1;
	
	pthread_create(&t1, NULL, func, NULL);
	
	x=1;
	int r=x;
	
	pthread_join(t1, NULL);
	
	return 0;
}

void *func(void *ptr){
	
	x=1;
}
