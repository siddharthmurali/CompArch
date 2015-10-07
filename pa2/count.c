#include <stdio.h>
#include <stdlib.h>


long int convert(char* hexInput){

	//printf("test");

	char *ptr;
	long val;

	val = strtoul(hexInput, NULL, 16);

	printf("%ld\n", val);

	return val;

}

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("error\n");
		return -1;
	}


	long hexConvert = 0;
	hexConvert = convert(argv[1]);

	return 0;

}


