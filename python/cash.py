from cs50 import get_float

total = 0

while True:
    reais = get_float("Reais: ")*100
    if reais > 0:
        break

while reais >= 25:
    reais = reais - 25
    total += 1
while reais >= 10:
    reais = reais - 10
    total += 1
while reais >= 5:
    reais = reais - 5
    total += 1
while reais >= 1:
    reais = reais - 1
    total += 1

print(f"Moedas: {total}")
