#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


//global
int x=0;
int y=0;

void *func1(void *);
void *func2(void *);

pthread_mutex_t l;
// = PTHREAD_MUTEX_INITIALIZER;
int main(){
	//global
	pthread_t t1;
	pthread_t t2;
	
	if (pthread_mutex_init(&l, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
	
	pthread_create(&t1, NULL, func1, NULL);
	pthread_create(&t2, NULL, func2, NULL);
	
	
	for(int i=0; i<2; i++){
		pthread_mutex_lock(&l);
		x=1;
		y=1;
		pthread_mutex_unlock(&l);
	}
		
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	pthread_mutex_destroy(&l);
	
	return 0;
}

void *func1(void *ptr){
	for(int i=0; i<2; i++){
		pthread_mutex_lock(&l);
		x=0;
		pthread_mutex_unlock(&l);
		if(x>0){
			y++;
			x=2;
		}
	}
}

void *func2(void *ptr){
	if(x>1){
		if(y==3){
			//exit(-1);
			printf("*****error*****\n");
		}
		else{
			y=2;
		}
	}
	
}
