#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

main (int argc, char *argv[]){

	if(argc != 2){
		printf("error\n");
	}
	
	else{

		int number = atoi(argv[1]);
	
		if( number == 0){
			
			printf("error\n");
		}		

		if( number != 0 &&  (number % 2) == 0){

			printf("even\n");
		}
	

		if( number != 0 && (number % 2) != 0){

			printf("odd\n");
		}

	}

}




