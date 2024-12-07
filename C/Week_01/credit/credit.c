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

// Função para verificar se a entrada contém apenas números
int only_numeric() {
    for (int i = 0; credit_card_number[i] != '\0'; i++) {
        if (!isdigit(credit_card_number[i])) {
            return 0;
        }
    }
    return 1;
}

// Implementação do algoritmo de Luhn
int luhn_algorithm() {
    int sum_of_products = 0; // Soma dos produtos multiplicados por 2
    int sum_of_sum = 0;      // Soma dos outros números do cartão

    // Multiplicando os números do cartão (penúltimo para o primeiro, de 2 em 2)
    for (int i = strlen(credit_card_number) - 2; i >= 0; i -= 2) {
        int number = credit_card_number[i] - '0'; // Convertendo char para int

        number *= 2; // Multiplicando o número por 2

        // Se o produto for maior que 9, somamos os dois dígitos
        if (number > 9) {
            number = (number / 10) + (number % 10);
        }

        sum_of_products += number; // Acumulando o resultado
    }

    // Somando os outros dígitos (aqueles que não foram multiplicados por 2)
    for (int i = strlen(credit_card_number) - 1; i >= 0; i -= 2) {
        sum_of_sum += credit_card_number[i] - '0';
    }

    // Verifica se a soma final é divisível por 10
    return (sum_of_products + sum_of_sum) % 10 == 0;
}

int main(void) {
    printf("Credit Card Number: ");
    scanf("%16s", credit_card_number); // Lê o número do cartão como string
    char card_enterprise[20] = "INVALID"; // Inicializa como "INVALID"

    // Verifica se a entrada contém apenas números
    if (!only_numeric()) {
        printf("INVALID\n");
        return 0;
    }

    // Verifica se o cartão é válido pelo algoritmo de Luhn
    if (!luhn_algorithm()) {
        printf("INVALID\n");
        return 0;
    }

    // Verificando a marca do cartão de crédito
    int length = strlen(credit_card_number);
    if (credit_card_number[0] == '4' && (length == 13 || length == 16)) {
        // VISA começa com 4 e possui 13 ou 16 dígitos
        strcpy(card_enterprise, "VISA");
    }
    else if (credit_card_number[0] == '3' && length == 15 && (credit_card_number[1] == '4' || credit_card_number[1] == '7')) {
        // AMEX começa com 34 ou 37 e possui 15 dígitos
        strcpy(card_enterprise, "AMEX");
    }
    else if (credit_card_number[0] == '5' && length == 16 &&
            credit_card_number[1] >= '1' && credit_card_number[1] <= '5') {
        // MASTERCARD começa com 51 a 55 e possui 16 dígitos
        strcpy(card_enterprise, "MASTERCARD");
    }

    // Se nenhuma marca for identificada, retorna "INVALID"
    if (strcmp(card_enterprise, "INVALID") == 0) {
        printf("INVALID\n");
        return 0;
    }

    // Caso o cartão seja válido, imprime a marca
    printf("%s\n", card_enterprise);
    return 0;
}
