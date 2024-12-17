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

# AMEX 15 digitos - 34 ou 37
# MasterCard 16 digitos - 51 52 53 54 55
# Visa 13 ou 16 - 4

import re

if __name__ == "__main__":
    credit_card_number: str = input(f"Credit card number: ")
    credit_card_number = re.sub(r'\D', '', credit_card_number) # Removendo tudo que não é número
    credit_card_numbers_multiplied: list = []
    credit_card_numbers_to_sum: list = []

    for i in range(len(credit_card_number)-2, -1, -2):
            product: int = int(credit_card_number[i]) * 2

            if product > 9:
                # Seo produto for maior que 9 somamos os 2 digitos
                product = sum(int(number) for number in str(product))

            credit_card_numbers_multiplied.append(product)

    sum_of_products: int = sum(credit_card_numbers_multiplied)
    # print("\nNumeros multiplicados ", *credit_card_numbers_multiplied)
    # print(sum_of_products)

    for i in range(len(credit_card_number)-1, -1, -2):
         credit_card_numbers_to_sum.append(int(credit_card_number[i]))

    sum_of_sum: int = sum(credit_card_numbers_to_sum)
    # print("\nNumeros para somar ", *credit_card_numbers_to_sum)
    # print(sum_of_sum)

    card_network: str = None
    # Verificando se o cartão é da visa
    if credit_card_number[0] == '4' and (len(credit_card_number) == 13 or len(credit_card_number) == 16):
        card_network: str = "VISA"

    # Verificando se o cartão é AMEX
    elif credit_card_number[0] == '3' and (credit_card_number[1] == '4' or credit_card_number[1] == '7') and len(credit_card_number) == 15:
        card_network: str = "AMEX"

    # Verificando se o cartão é MasterCard
    elif credit_card_number[0] == '5' and len(credit_card_number) == 16:
        for i in range(5):
            if credit_card_number[1] in ['1', '2', '3', '4', '5']:
                card_network: str = "MASTERCARD"
                break


    # Caso o cartão seja válido
    if card_network and (sum_of_products + sum_of_sum) % 10 == 0:
         print(card_network)
    else:
         print("INVALID")
