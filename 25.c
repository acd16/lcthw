#include "25.h"

int main(){
		int age = 0;
		char initial = '\0';
		char * name = NULL;
		printf("Enter age\n");
		check(read_scan("%d", &age) == 0, "error in read_scan");
		printf("Enter initial\n");
		check(read_scan("%c", &initial) == 0, "error in read_scan");
		fflush(stdout);
		printf("Enter name\n");
		check(read_scan("%s", &name) == 0, "error in read_scan");
		name[strcspn(name, "\n")] = 0;
		log_info("Details : %c %s %d", initial, name, age);
error:
		return -1;
}

int read_scan(char * inp, ...){
	va_list ap;
	char * ch;
	int * in;
	char ** st;
	int i = 0;
	va_start(ap, inp);
	while(inp[i] != 0){
		if(inp[i] == '%'){
			switch(inp[i+1]){
				case 'c':
					ch = va_arg(ap, char *);
					*ch = fgetc(stdin);
					break;
				case 'd':
					in = va_arg(ap, int *);
					read_int(in);
					break;
				case 's':
					st = va_arg(ap, char **);
					read_string(st, MAX_DATA);
					break;
				default:
					sentinal("unknown format");
					
			}
		}else{
		fgetc(stdin);
	}
		i++;
	}
	va_end(ap);
	return 0;
error:
	return 1;
}

int read_string(char ** str, int maxSize){
	*str = malloc(sizeof(char) * maxSize + 1);
	check(fgets(*str, maxSize, stdin) != NULL, "fgets error");
	return 0;
error:
	if(*str)
		free(*str);
	return 1;
}

int read_int(int * i){
	char * ch;
	check(read_string(&ch, MAX_DATA) == 0, "string read err bef atoi");
	*i = atoi(ch);
	return 0;
error:
	return 1;
}
