/*
    enunciado:

    argv[27] = {NQXPOMAFTRHLZGECYJIUWSKDVB} nqxpomaftrhlzgecyjiuwskdvb
    sentence = {ABCD}
    saida: NQXP

    as letras que você colocou no terminal estão na mesma ordem das letras do alfabeto
    se em sentence tiver um Z ele vai valer B
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char alphabet_cipher[28]; // 28 pois como uso fgets ele coloca um /n e um \0 no final
    char sentence[100];

    do{
        printf("Alphabet Cipher (26 characters): "); fgets(alphabet_cipher, 100, stdin);
    } while(strlen(alphabet_cipher) != 27); //27 pois fgets adiciona um \n no final

    printf("plaintext: "); fgets(sentence, 100, stdin);

    for(int i = 0; sentence[i] != '\0'; i+=1){
        // Verifdicando se é uma letra
        if (isalpha(sentence[i])){
            // calculando pelo alfabeto original
            int ascii = toupper(sentence[i]) - 'A';

            //Verificando se é maiuscula ou minuscula
            if(islower(sentence[i])){
                sentence[i] = tolower(alphabet_cipher[ascii]);
            } else {
                sentence[i] = toupper(alphabet_cipher[ascii]);
            }
        }
    }

    printf("ciphertext: %s", sentence);
    return 0;
}


//Codigo usando argumentos de terminal que enviei pra harvard
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main(int argc, char *argv[]) {
//     // verifica se tem apenas um argumento de key
//     if(argc != 2){
//         printf("\n usage: ./substitution key\n\n");
//         return 1;
//     }

//     // Caso o tamanho da string seja diferente de 26
//     if (strlen(argv[1]) != 26){
//         printf("Key must contain 26 characters.\n\n");
//         return 1;
//     }


//     for(int i = 0; argv[1][i] != '\0'; i+=1){
//         // Caso não tenham apenas letras do alfabeto
//         if(!isalpha(argv[1][i])){
//             printf("\n usage: ./substitution key\n\n");
//             return 1;
//         }

//         // Verificando duplicatas
//         for(int j = i + 1; j < strlen(argv[1]); j+=1){
//             if(argv[1][i] == argv[1][j]){
//                 printf("\nKey must not contain duplicate characters.\n\n");
//                 return 1;
//             }
//         }

//     }

//     char sentence[100];
//     printf("plaintext: "); fgets(sentence, 100, stdin);

//     for(int i = 0; sentence[i] != '\0'; i+=1){
//         // Verifdicando se é uma letra
//         if (isalpha(sentence[i])){
//             // calculando pelo alfabeto original
//             int ascii = toupper(sentence[i]) - 'A';

//             //Verificando se é maiuscula ou minuscula
//             if(islower(sentence[i])){
//                 sentence[i] = tolower(argv[1][ascii]);
//             } else {
//                 sentence[i] = toupper(argv[1][ascii]);
//             }
//         }
//     }

//     printf("ciphertext: %s", sentence);
//     return 0;
// }
