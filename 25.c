#include "25.h"

int main(){
		int age = 0;
		char initial = '\0';
		char * name = NULL;
		printf("Enter age\n");
		check(read_scan("%d", &age) == 0, "error in read_scan");
		printf("Enter initial\n");
		check(read_scan("%c", &initial) == 0, "error in read_scan");
		printf("Enter name\n");
		check(read_scan("%d", &name) == 0, "error in read_scan");
		log_info("Details : %c %s %d", initial, name, age);
error:
		return -1;
}

int read_scan(char * inp, ...){
}

int read_string(char ** str, int maxSize){
}

int read_int(int * i){
}
