/*
  enunciado: https://cs50.harvard.edu/x/2024/psets/2/readability/

  - Palavras longas aumentam o nivel da leitura
  - mais palavras em uma frase aumentam o nivel

    L = letras / palavras * 100
    S = frases / palavras * 100

    Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8

    se for menor que 1: Before Grade 1
    
    entre: Grade (de 1 ate 15)

    se for >= 16: Grade 16+
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

const int TAM = 10000;

int main(){
    char text[TAM];
    int letters = 0;
    int words = 1;
    int sentences = 0;
    float S, L;
    float index = 0;

    printf("text: "); fgets(text, TAM, stdin);

    // Contador de letras na frase
    for(int i = 0; i < strlen(text); i+=1){
        if(isalpha(text[i])){
            letters += 1;
        } else if(text[i] == ' '){
            words += 1;
        } else if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            sentences += 1;
        }
    }

    L = ((float)letters / words) * 100;
    S = ((float)sentences / words) * 100;

    index = 0.0588 * L - 0.296 * S - 15.8;
    int index_int = round(index);
    
    if (index_int < 1){
        printf("Before Grade 1\n");
    } else if (round(index) >= 16){
        printf("Grade 16+\n");
    } else {
        printf("Grade %.d\n", index_int);
    }
}   