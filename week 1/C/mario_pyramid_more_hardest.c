/*
   Enunciado -> https://cs50.harvard.edu/x/2024/psets/1/mario/more/
*/

#include <stdio.h>

int main() {
    int height;
    int quantity_hashtags = 1;
    int valid_input = 0;

    while(!valid_input){
        printf("Height: ");
        if (scanf("%d", &height) == 1 && height > 0){
            valid_input = 1;
        } else {
            while(getchar() != '\n');
            printf("\nATENTION\n");
            printf(" - 0 is not a valid input\n");
            printf(" - Enter a value of type int\n\n");
        }
    }

    int quantity_spaces = height - 1;

    for(int i = 0; i < height; i+=1){

        for(int j = 0; j < quantity_spaces; j+=1){
            printf(" ");
        }

        for(int k = 0; k < quantity_hashtags; k+=1){
                printf("#");
        }
        
        printf("  ");

        for(int k = 0; k < quantity_hashtags; k+=1){
                printf("#");
        }
        quantity_hashtags+=1;
        quantity_spaces-=1;
        printf("\n");
    }

    return 0;
}