#include<stdio.h>

void print(int *i, char **ch){
    int *j=i;
    for(;(j-i)<4;j++, (ch)++){
        printf("%d %s\n", *j, *ch);
        printf("%p %p\n", j, i);
        *j = 4;
        printf("%d this\n", *j);
    }
}

int main(){
    int i[] = {1,2,3,4};
    char *ch[] = {"this", "that", "also", "and"};
    int cout = sizeof(i)/sizeof(int);
    int *j = i;
    char **ci = ch;
    int k=0;
    for(k=0;k<cout;k++){
        printf("%d %s\n", j[k], ci[k]);
    }
    for(k=0;k<cout;k++){
        printf("%d %s\n", *(j+k), *(ci+k));
    }
    printf("count is %d\n", cout);
    print(i,ch);
    for(k=0;k<cout;k++){
        printf("%d ",j[k]);
    }
    printf("\n");
    return 1;
}
