'''
Enunciado -> https://cs50.harvard.edu/x/2024/psets/1/mario/more/
'''

if __name__ == "__main__":
    while True:
        quantity_hashtags: int = 1
        try:
            height: int = int(input("Height: "))

            if height == 0:
                print("\n\nATENTION\n"
                  " - 0 is not a valid input\n\n")
                continue
            
        except ValueError:
            print("\n\nATENTION\n"
                  " - it's not an int input\n\n")
            continue
        
        quantity_spaces: int = height - 1
        for _ in range(height):
            print(' ' * quantity_spaces, end='')
            print('#' * quantity_hashtags, end='')
            print('   ', end='')
            print('#' * quantity_hashtags)
            quantity_hashtags+=1
            quantity_spaces-=1