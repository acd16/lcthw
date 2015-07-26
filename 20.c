#include "dbug.h"


int test_check(char * file){
		FILE * pFp = fopen(file, "r");
		check(pFp, "File not found %s", file);
		return 0;
error:
		if(pFp) fclose(pFp);
		return -1;
}

int test_sentinal(int check){
		if(check != 1)
				sentinal("its not 1");
		return 0;
error:
		return -1;
}

int test_check_mem(){
		int * i = NULL;
		check_mem(i);
		return 0;
error:
		return -1;
}

int test_check_debug(){
		int i=2;
		check(i !=0, "i not zero");
		return 0;
error:
		return -1;
}


int main(){
		log_err("this is error");
		debug ("gg %d", 5);

		check(test_check("20.c") == 0, "file not found");
		check(test_sentinal(1) == 0, "test sentinal failed");
		check(test_check_mem() == -1, "check_mem failed");
		check(test_check_debug() == -1, "test check dbg failed");
		return 0;
error:
		return -1;
}
