from cs50 import get_string

s = get_string("Ponha seu texto aqui: ")
tamanho = 0
palavras = s.count(" ") + 1
pon = s.count(".") + s.count("!") + s.count("?")
for i in s:
    if i.isalpha():
        tamanho += 1

l = tamanho*100/palavras
k = pon*100/palavras
index = 0.0588 * l - 0.296 * k - 15.8


if (index < 1):
    print("Before Grade 1")
elif (index >= 16):
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
