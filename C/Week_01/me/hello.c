/*
  enunciado: https://cs50.harvard.edu/x/2024/psets/1/me/
*/

#include <stdio.h>

int main(){
    char name[100];
    printf("What's your name: "); scanf("%99s", name);
    printf("\nhello, %s", name); 
}