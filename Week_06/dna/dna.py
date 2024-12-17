import csv
import sys
import os

people_dna: dict = {}
sequence_file = None
list_of_longest_run: list = []

def data_base_selection(argv) -> None:
    if argv[1] == "databases/large.csv":
        with open(argv[1], mode='r') as file:
            archive = csv.DictReader(file) # Pegando o cabeçalho como as chaves
            for row in archive:
                name: str = row["name"]
                people_dna[name] = {
                    "AGATC": int(row["AGATC"]),
                    "TTTTTTCT": int(row["TTTTTTCT"]),
                    "AATG": int(row["AATG"]),
                    "TCTAG": int(row["TCTAG"]),
                    "GATA": int(row["GATA"]),
                    "TATC": int(row["TATC"]),
                    "GAAA": int(row["GAAA"]),
                    "TCTG": int(row["TCTG"])
                }

    elif argv[1] == "databases/small.csv":
        with open(argv[1], mode='r') as file:
            archive = csv.DictReader(file) # Pegando o cabeçalho como as chaves
            for row in archive:
                name: str = row["name"]
                people_dna[name] = {
                    "AGATC": int(row["AGATC"]),
                    "AATG": int(row["AATG"]),
                    "TATC": int(row["TATC"]),
                }
    else:
        print("File not found")
        sys.exit(2)

def main():
    if len(sys.argv) < 3:
        print("use: python dna.py database/csv_file sequences/txt_file")
        sys.exit(1)

    data_base_selection(sys.argv)

    # Verificando se o caminho para o segundo argumento existe
    if not os.path.exists(sys.argv[2]):
        print(f"File '{sys.argv[2]}' not found")
        sys.exit(1)

    with open(sys.argv[2], mode='r') as file:
        sequence_string = file.read() # Guardando o conteúdo do arquivo dentro de uma string


    # Guardando as maiores sequencias de cada STR
    for _, str in people_dna.items():
        for i in str.keys():
            str_name = i
            list_of_longest_run.append(longest_match(sequence_string, str_name))
        break


    # Checando DNA compativel
    for people_name, str in people_dna.items():
        index: int = 0
        for qtd_str in str.values():
            if qtd_str != list_of_longest_run[index]:
                break
            index+=1
        else:
            print(people_name)
            break
    else:
        print("No Match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run

if __name__ == "__main__":
    main()
