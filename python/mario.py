from cs50 import get_int

while True:
    altura = get_int("Height: ")
    if altura <= 8 and altura > 0:
        break


for i in range(altura):

    for k in range(altura - i - 1):
        print(" ", end="")
    for h in range(i + 1):
        print("#", end="")

    print("  ", end="")

    for j in range(i + 1):
        print("#", end="")
    print("")
