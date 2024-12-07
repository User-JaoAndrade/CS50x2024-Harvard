/*
  enunciado: https://cs50.harvard.edu/x/2024/psets/2/scrabble/

  //int score_list[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
//char letter_list[27] = {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q,  r, s, t, u, v, w, x, y,  z, \0};
*/

#include <stdio.h>

// Variáveis globais
int score_list[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char letter_list[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};


// Mexer nessa função
int score_calculation(char player_word[], int score_player){
  for(int i = 0; i <= strlen(player_word); i += 1){
    for(int j = 0; j < 26; j += 1){
      if (player_word[i] == letter_list[j]){
        score_player+=score_list[j];
      }
    }
  }
}

// Start
int main(void){
  char player01_word[100], player02_word[100];
  int score_player01 = 0, score_player02 = 0;
    
  printf("Player 1: "); scanf("%99s", player01_word);
  printf("Player 2: "); scanf("%99s", player02_word);
}