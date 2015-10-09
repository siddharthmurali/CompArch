#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
	long key;
	int value;
	struct Element* next;
} Element;

typedef struct Hashtable {
	int size;
	Element *table;
} HashTable;

int count;
int place;



HashTable *createTable(int size){

    int i;
    
	HashTable *numbers = malloc(sizeof(HashTable));
	numbers->table = malloc(sizeof(Element) * size);
	numbers->size = size;
	for(i=0; i<size; i++){
		numbers->table[i].key = 0;
		numbers->table[i].value = 0;
		//numbers->table->next->key = 0;
		//numbers->table->next->value = 0;
	}

	return numbers;
}

long makeKey(char *line){

	long key = strtoul(line, NULL, 16);
	return key;
	
}	
	

long hashFunction(long key, int size)
{
	return key % size;
}

int insertValue(long key, HashTable *numbers, int place){
    long h;
	int i;
    h = hashFunction(key, numbers->size);
    
		if(numbers->table[h].key == key){
	//		numbers->table[h].next->key = key;
	//		numbers->table[h].next->value = key;
			count--;
			return 0;
		}
	numbers->table[h].key = key;
	numbers->table[h].value = h;
	
	return 0;
		

}


int main(int argc, char **argv){

	int size = 100000000;
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
    
    
    count = 0;
    while(fgets(line, 100, fp) != NULL){
		count ++;
    }
   fclose(fp);
	FILE *infile = NULL;
   infile = fopen(argv[1], "r");
    while(fgets(line, 100, infile) != NULL){
	long key = makeKey(line);
	int i = insertValue(key, numbers, place);
	place++;
        if(i == -1){
        	return -1;
        }
    }
   
	printf("%d\n", count); 
    free(numbers->table);
    free(numbers);
    return 0;
}
