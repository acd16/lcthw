#include <stdio.h>
#include <stdlib.h>

#define MAX_ELE 50

typedef int (*cmp)(int, int);

void bubble_sort(int * start, int num, cmp gg){
	int i, j, temp;
	for (i=0;i<num;i++){
		for(j=0;j<num;j++){
			if(gg(start[i], start[j])){
				temp = start[i];
				start[i]=start[j];
				start[j]=temp;
			}
		}
	}
}

int big(int i, int j){
	return (i>j) ? 0:1;
}

int small(int i, int j){
	return (i<j) ? 0:1;
}

void print(int * start, int num){
	int i;
	for(i=0;i<num;i++)
		printf("%d ", start[i]);
	printf("\n");
}

int main(int argc, char **argv){
	int i = 0;
	int arr[MAX_ELE] = {0};
	for(i=0;i<argc-1;i++)
			arr[i] = atoi(argv[i+1]);
	print(arr, argc-1);
	bubble_sort(arr, argc-1, big);
	print(arr, argc-1);
	bubble_sort(arr, argc-1, small);
	print(arr, argc-1);
	return 0;
}
