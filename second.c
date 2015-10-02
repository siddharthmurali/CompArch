#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


main(int argc, char *argv[]){

   	if( argc == 2){

		int number = atoi(argv[1]);	

		if ( ((number % 2) == 0 ) || ((number % 3) == 0) || ((number % 5) == 0) ) {

			printf("no\n");

		}

		else{

			printf("yes\n");
		}
	}

	else{

		printf("error\n");

	}
}



   


