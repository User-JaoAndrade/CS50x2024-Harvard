/*
   Enunciado: https://cs50.harvard.edu/x/2024/psets/1/cash/
*/

#include <stdio.h>

// Variaveis Globais
int user_cash;
int notes = 0;

void generating_change(int coin){
    while(user_cash >= coin){
        user_cash -= coin;
        notes += 1;
    }
}

int main(void){
   int valid_input = 0;

   while(!valid_input){
    printf("Cash: ");

    if(scanf("%d", &user_cash) == 1 && user_cash != 0){
        valid_input = 1;
    } else {
        while(getchar() != '\n');
        printf("\nATENTION\n");
        printf("- Enter a value greater then 0 and of type int\n");
    }
   }

    generating_change(25);
    generating_change(10);
    generating_change(5);
    generating_change(1);

    printf("%d", notes);

    return 0;
}