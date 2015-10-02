#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char **argv){

	FILE *fp = NULL;
	char *line = malloc(1000);
	
	if(argc == 2){
		fp = fopen(argv[1], "r");
	}
	else if(argc >2){
		printf("error\n");
		return -1;
	}
	else if(argc <2){
		printf("error\n");
		return -1;
	}

	if(fp == NULL){
		printf("error\n");
		return -1;
	}

	int len = 100;
	char *first = malloc(1000);
	int firstM = 0;
	int firstN = 0;
	int lineCount = 0;
	char *currLine = malloc(1000);
	int matrixOne[100];
	int matrixTwo[100];
	int matrixThree[100];
	first = fgets(line, len, fp);
	//lineCount ++;

	if(first[0] != first[2]){
		printf("error\n");
		return -1;
	}
	if(line[0] == line[2]){
		firstM = atoi(&first[0]);
		firstN = atoi(&first[2]);
	}
	
	const char s[100] = "	";
	char *token;
	int test;
	int matrixLen = firstM * firstN;
	int matrixCount = 0;
//	printf("%d\n", matrixLen);
	while(lineCount < firstM){
		currLine = fgets(line, len, fp);
		token = strtok(currLine, s);
		while(token != NULL){
			test = atoi(token);
		//	printf("%d\n", test);
			matrixOne[matrixCount] = test;
		//	printf("%d\n", matrixOne[matrixCount]);
			matrixCount++;
			token = strtok(NULL, s);
		}

		lineCount ++;
	}

	
	fgets(line, len, fp);

//	printf("\n");

	lineCount = 0;
	matrixCount = 0;
	while(lineCount < firstM){
		currLine = fgets(line, len, fp);
		token = strtok(currLine, s);
		while(token != NULL){
			test = atoi(token);
			matrixTwo[matrixCount] = test;
			//printf("%d\n", matrixTwo[matrixCount]);
			matrixCount ++;
			token = strtok(NULL, s);
		}
		lineCount ++;
	}
 			
//	printf("\n");

	matrixCount = 0;
	while(matrixCount < matrixLen){
		matrixThree[matrixCount] = matrixOne[matrixCount] + matrixTwo[matrixCount];
	//	printf("%d\n", matrixThree[matrixCount]);
		matrixCount ++;
	}

	int printCount = 0;
	int printCount2 = 1;
	while(printCount < matrixLen){
		printf("%d	", matrixThree[printCount]);
		if(printCount2 == firstN){
			printf("\n");
			printCount2 = 0;
		}
		printCount++;
		printCount2++;
	}
	

	return 0;

}


