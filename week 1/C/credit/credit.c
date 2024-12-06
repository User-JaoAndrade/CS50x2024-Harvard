/*
Enunciado: https://cs50.harvard.edu/x/2024/psets/1/credit/

NUMERO CARTAO DE EXEMPLO: 5285488875495428

1 - Multiplicar por 2 a partir do penultimo digito ate o primeiro de 2 em 2
    ex: MULTIPLICAR OS NUMEROS: 2 5 4 7 8 4 8 5 por 2
    caso o resultado da multiplicação for  > 9 somamos os 2 digitos 
    ex: 
        6 x 2 = 12
        1 + 2 = 3

2 - Somar os resultados das multiplicações 
3 - Somar os outros digitos (2 5 8 8 5 9 4 8)
4 - Somar os resultados dos passos anteriores
5 - pegar o resto da divisão do resultado do passo 4 por 10
6 - se o resto for == 0 o cartão de crédito é válido

PS: Deixei uns comentários com um código printf caso queiram ver os números se desenrolando
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char credit_card_number[17];

int only_numeric(){
    for(int i = 0; credit_card_number[i] != '\0'; i++){
        if(!isdigit(credit_card_number[i])){
            return 0;
        }
    }
    return 1;
}

int luhn_algorithm(){
    int sum_of_products = 0; //Variavel que vai guardar o valor da soma dos produtos
    int sum_of_sum = 0; //Variavel que vai guardar a soma dos outros números do cartão

    //Multiplicando os números do cartão a partir do penultimo digito de forma decrescente
    //de 2 em 2
    for(int i = strlen(credit_card_number) - 2; i >= 0; i -= 2){
        int number = credit_card_number[i] - '0'; //Convertendo o char pra um tipo int

        number *= 2;

        if (number > 9){
            number = (number / 10) + (number % 10);
        }

        sum_of_products += number;
    }
    //printf("\nSoma dos numeros multiplicados: %d", sum_of_products);

    //Somando os outros digitos
    for (int i = strlen(credit_card_number) - 1; i > 0; i-=2){
        sum_of_sum+=credit_card_number[i] - '0';
    }
    //printf("Soma dos outros nnmeros do cartao: %d", sum_of_sum);

    return (sum_of_products + sum_of_sum) % 10 == 0;
}

int main(void){
    printf("Credit Card Number: "); 
    scanf("%16s", credit_card_number);
    char card_enterprise[17];

    if(!only_numeric()){
        printf("Please, only provide numbers\n");
        return 0;
    }

    // Verificando a marca do cartão de crédito
    if (credit_card_number[0] == '4'){
        strcpy(card_enterprise, "VISA");
    } else if (credit_card_number[0] == '3' && (credit_card_number[1] == '4' || credit_card_number[1] == '7')){
        strcpy(card_enterprise, "American Express");
    } else if (credit_card_number[0] == '5'){
        for(int i = 1; i < 6; i+=1){
            int number = credit_card_number[1] - '0';
            if (number == i){
                strcpy(card_enterprise, "Master Card");
            }
        }
    } else {
        strcpy(card_enterprise, "unknown Card");
    }

    // Verificando se o cartão é válido
    if (!luhn_algorithm()){
        printf("INVALID");
    } else {
        printf("%s\n", credit_card_number);
        printf("%s", card_enterprise);
    }

    return 0;
}