/*
  enunciado: https://cs50.harvard.edu/x/2024/psets/2/caesar/
  formula: ci = (pi + k) % 26
  ci e pi = a letra atual do alfabeto
  k = key

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int TAM = 100;

int main(){
    char sentence[TAM];
    int key;
    printf("key: "); scanf("%d", &key);
    getchar();
    printf("plaintext: "); fgets(sentence, TAM, stdin);

    for (int i = 0; sentence[i] != '\0'; i += 1){
        if(isalpha(sentence[i])){
            // Verificando se a letra é minuscula
            if(islower(sentence[i])){
                sentence[i] = (sentence[i] - 'a' + key) % 26 + 'a';
            } else {
                sentence[i] = (sentence[i] - 'A' + key) % 26 + 'A';
            }
        }
    }

    printf("ciphertext: %s", sentence);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// int main(int argc, char *argv[]) {
//     // Verifica se exatamente um argumento foi passado (a chave)
//     if (argc != 2) {
//         printf("Usage: ./caesar key\n");
//         return 1;
//     }

//     // Converte a chave de string para inteiro e verifica se é válida
//     char *endptr;
//     int key = strtol(argv[1], &endptr, 10);

//     // Se a chave não for um número válido
//     if (*endptr != '\0' || key <= 0) {
//         printf("Usage: ./caesar key\n");
//         return 1;
//     }

//     // Solicita o texto a ser criptografado
//     char sentence[100];
//     printf("plaintext: ");
//     fgets(sentence, 100, stdin);

//     // Criptografa o texto
//     for (int i = 0; sentence[i] != '\0'; i++) {
//         if (isalpha(sentence[i])) {
//             if (islower(sentence[i])) {
//                 sentence[i] = (sentence[i] - 'a' + key) % 26 + 'a';
//             } else {
//                 sentence[i] = (sentence[i] - 'A' + key) % 26 + 'A';
//             }
//         }
//     }

//     // Exibe o texto criptografado
//     printf("ciphertext: %s", sentence);

//     return 0;
// }
