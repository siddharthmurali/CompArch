#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

struct list{

        int val;
        struct list *next;
};

struct list *head = NULL;


int addToList(int val){

	struct list *ptr;
	struct list *lag;
	struct list *tmp;

	ptr = (struct list*)malloc(sizeof(struct list));
	ptr -> val = val;
	ptr -> next = NULL;

	if(head == NULL){
		head = ptr;
		return 0;
	}

	if(head != NULL){
		lag = NULL;
        	tmp = head;
        
        	while(tmp &&( tmp->val <= val)){
            		if(tmp->val == val){
                		free(ptr);
                		return 0;
            		}
            		lag = tmp;
            		tmp = tmp->next;
        	}
        
        	if(!tmp){
            		lag->next = ptr;
    		 }
		else{
            		if(lag){
                		ptr->next = lag->next;
                		lag->next = ptr;
   		         }
			else{
                		ptr->next = head;
                		head = ptr;
            		}
        	}
	}

	return 0;
}


int deleteFromList(int val){

	struct list *lag;
	struct list *tmp;
    
   	 if(head == NULL){
        	return 0;
	 }
	else if(head->val == val){
        	tmp = head;
        	head = head->next;
        	free(tmp);
        	return 0;
    	}
	else{
        	lag = NULL;
        	tmp = head;
        	while(tmp != NULL && tmp->val <= val){
            		if(tmp->val == val){
                		lag->next = tmp->next;
                		free(tmp);
                		return 0;
            		}
            	lag = tmp;
           	tmp = tmp->next;
        	}
   	}

        return 0 ;
}


void printList(){
    
    struct list *lag = head;
    struct list *tmp = head;
    
    
    while(tmp){
        printf("%d ", tmp->val);
        lag = tmp;
        tmp = tmp->next;
    }
    
    printf("\n");
    
    return;
}


int readLine(char *line){
    
    int i;
    char *num;
    int val;
    
    
    if(line[0] != 'i' && line[0] != 'd'){
        printf("error\n");
        return -1;
    }
    
    if(isdigit(line[2]) == 0){
        printf("error\n");
        return -1;
    }
    
    i = 2;
    
    while(isdigit(line[i]) > 0 && i < strlen(line)){
        i++;
    }
    
    
    num = &line[2];
    value = atoi(num);
    
    
    if(line[0] == 'i'){
        
        int x = addToList(val);
        
        if(x == -1){
            return -1;
       	}
    }else if(line[0] == 'd'){
        int x = deleteFromList(val);
        if(x == -1){
            return -1;
       	}
    }
    
    return 0;
    
}


int  main(int argc, char * argv[]){

	FILE *infile = NULL;
	char *line = malloc(101);
	int Linelen = 100;
	int y;
	int val;
	char *x;

	if(argc == 2){
		infile = fopen(argv[1], "r");
	}
	if(argc > 2){
		printf("error\n");
		return -1;
	}
	if(argc<2){
		printf("error\n");
		return -1;
	}

	if(infile == NULL){
		printf("error\n");
		return -1;
	}

	while(fgets(line, Linelen, infile) != NULL){
		y = readLine(line);
		if(y== -1){
			return -1;
		}
	}


	printList();
	free(head);

	return 0;
}







