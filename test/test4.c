#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


//global
int x=0;
int y=0;
int z=0;

void *func1(void *);
void *func2(void *);


int main(){
	//global
	pthread_t t1;
	pthread_t t2;
	
	
	
	pthread_create(&t1, NULL, func1, NULL);
	pthread_create(&t2, NULL, func2, NULL);
	
	
	x=1;

		
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}

void *func1(void *ptr){
	int r=y;
	int r1=x;
}

void *func2(void *ptr){
	int r=z;
	int r1=x;
}
