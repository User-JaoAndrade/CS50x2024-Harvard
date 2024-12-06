"""
Enunciado: https://cs50.harvard.edu/x/2024/psets/1/credit/

NUMERO CARTAO DE EXEMPLO: 5285 4888 7549 5428

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

PS: Deixei uns comentários com um código print caso queiram ver os números se desenrolando
"""
import re

if __name__ == "__main__":
    credit_card_number: str = input(f"Credit card number: ")
    credit_card_number = re.sub(r'\D', '', credit_card_number) # Removendo tudo que não é número
    credit_card_numbers_multiplied: list = []
    credit_card_numbers_to_sum: list = []

    for i in range(len(credit_card_number)-2, -1, -2):
            product: int = int(credit_card_number[i]) * 2
            if product > 9:
                product: str = str(product)
                product_left: str = product[ :1]
                product_right: str = product[1: ]
                credit_card_numbers_multiplied.append(int(product_left) + int(product_right))
            else:
                 credit_card_numbers_multiplied.append(product)
    else:
         sum_of_products: int = sum(credit_card_numbers_multiplied)
         # print("\nNumeros multiplicados ", *credit_card_numbers_multiplied)
         # print(sum_of_products)

    for i in range(len(credit_card_number)-1, 0, -2):
         credit_card_numbers_to_sum.append(int(credit_card_number[i]))
    else:
        sum_of_sum: int = sum(credit_card_numbers_to_sum)
        # print("\nNumeros para somar ", *credit_card_numbers_to_sum)
        # print(sum_of_sum)

    if (sum_of_products + sum_of_sum) % 10 == 0:
         print(f"Credit Card {credit_card_number} is valid")
    else:
         print(f"Credit Card {credit_card_number} is invalid")
    