#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct person{
    char * name;
    int age;
    int height;
    int weight;
}pers;

void create_pers(pers ** inp, char * name, int age, int height, int weight){
    *inp = malloc(sizeof(pers));
	(*inp)->name = malloc(MAX_NAME_LEN * sizeof (char));
    strcpy((*inp)->name, name);
    (*inp)->age = age;
    (*inp)->height= height;
    (*inp)->weight= weight;
}

void print_pers(pers *inp){
    printf("Info %s %d %d %d\n", inp->name, inp->age, inp->height,inp->weight);
}

void destroy_pers(pers *inp){
    if(inp){
		if(inp->name)
			free(inp->name);
        free(inp);
	}
}

int main(){
    pers * a, *b;
    char name1[50] = "Adam";
    char name2[50] = "Eve";
    create_pers(&a, name1, 20, 30, 40);
    create_pers(&b, name2, 30, 40, 50);
    print_pers(a);
    print_pers(b);
    destroy_pers(a);
    destroy_pers(b);
    return 1;
}
