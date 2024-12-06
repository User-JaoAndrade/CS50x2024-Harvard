"""
Enunciado: 
"""
def generating_change(coin) -> None:
    global notes, user_cash

    while user_cash >= coin:
        user_cash -= coin
        notes += 1

if __name__ == "__main__":
    notes: int = 0
    user_cash: int = int(input("Cash owed: "))

    generating_change(25)
    generating_change(10)
    generating_change(5)
    generating_change(1)

    print(notes)


"""MINHA PRIMEIRA LÓGICA"""

# def generating_change(coin) -> None:
#     global notes, user_cash

#     while user_cash != 0:
#         user_cash -= coin
#         if user_cash == 0:
#             notes += 1
#             break

#         elif user_cash < 0:
#             user_cash += coin
#             break

#         else:
#             notes += 1

# if __name__ == "__main__":
#     notes: int = 0
#     user_cash: int = int(input("Cash owed: "))

#     generating_change(25)
#     generating_change(10)
#     generating_change(5)
#     generating_change(1)

#     print(notes)