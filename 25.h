#include <stdio.h>
#include "dbug.h"
#include <stdarg.h>
#include <stdlib.h>

#define MAX_DATA 12

int read_scan(char * inp, ...);
int read_string(char ** str, int maxSize);
int read_int(int * i);
