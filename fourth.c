#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
	int key;
	int value;
} Element;

typedef struct Hashtable {
	int size;
	Element *table;
} HashTable;


HashTable *createTable(int size){
    
    int i;
    
	HashTable *numbers = malloc(sizeof(HashTable));
	numbers->table = malloc(sizeof(Element) * size);
	numbers->size = size;
	
	for(i=0; i<size; i++){
		numbers->table[i].key = 0;
		numbers->table[i].value = 0;
	}
	
	return numbers;
}

int makeKey(char *line){

	int key = atoi(line);
	return key;
	
}	
	

int hashFunction(int key, int size)
{
    return (key % size);
}

int insertValue(int key, HashTable *numbers){

    int h, i;
    
    h = hashFunction(key, numbers->size);
    i = 0;
	
	while(numbers->table[h].key != 0 && (i < numbers->size)){
		
		if(numbers->table[h].key == key){
			return -1;
		}
		
		h = (h + 1) % numbers->size;
	}
	
	if(numbers->table[h].key == 0){
		numbers->table[h].key = key;
		numbers->table[h].value = h;
		return 0;
	}
	
	return 0;	
}

int searchValue(int key, HashTable *numbers){
    
    int h, i;
    
    h = hashFunction(key, numbers->size);
    i = 0;
    
	while(numbers->table[h].key != 0 && (i < numbers->size)){
		
		if(numbers->table[h].key == key){
			return 0;
		}
		h = (h + 1) % numbers->size;
	}
	
	return -1; 

} 

int lineReader(char *line, HashTable *numbers){

	int key;
    int x;

	if(line[0] == 'i' || line[0] == 'I'){
			key = makeKey(&line[2]);
       		x = insertValue(key, numbers);
       		if(x == -1){
       			printf("duplicate\n");
       			return 0;
       		}else{
       			printf("inserted\n");
       			return 0;
       		}
    }else if(line[0] == 's' || line[0] == 'S'){
    		key = makeKey(&line[2]);
       		x = searchValue(key, numbers);
        	if(x == -1){
        		printf("absent\n");
       			return 0;
       		}else{
       			printf("present\n");
       			return 0;
       		}
    }else{
    		printf("error\n");
    		return 0;
    }
}


int main(int argc, char **argv){

	int size = 1000;
    char *line = malloc(101);
    int len;
    HashTable *numbers;
    FILE *fp = NULL;
    
    numbers = createTable(size);
	
    
    if(argc == 2){
        fp = fopen(argv[1], "r");
    }else if(argc > 2){
        printf("error\n");
        return -1;
    }else if(argc < 2){
        printf("error\n");
        return -1;
    }
    
    if(fp == NULL){
        printf("error\n");
        return -1;
    }
    
    
     
    while(fgets(line, 100, fp) != NULL){
        int i = lineReader(line, numbers);
        if(i == -1){
        	return -1;
        }       
    }
    
    free(numbers->table);
    free(numbers);
    
    return 0;
}
