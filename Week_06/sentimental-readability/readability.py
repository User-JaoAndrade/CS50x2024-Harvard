'''
  enunciado: https://cs50.harvard.edu/x/2024/psets/2/readability/

  - Palavras longas aumentam o nivel da leitura
  - mais palavras em uma frase aumentam o nivel

  - contar as letras
  - contar as palavras (se encontrar um espaço é uma palavra)
  - contar as frases ('.' '!' '?')

    L = letras / palavras * 100
    S = frases / palavras * 100

    Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8

    se for menor que 1: Before Grade 1

    entre: Grade (de 1 ate 15)

    se for >= 16: Grade 16+
'''

text: str = input("Text: ")

num_letters: int = sum(1 for letra in text if letra.isalpha())
num_words: int = len(text.split())
num_sentences: int = sum(1 for i in text if i in ['.', '!', '?'])

l: float = num_letters / num_words * 100
s: float = num_sentences / num_words * 100

index: int = round(0.0588 * l - 0.296 * s - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
