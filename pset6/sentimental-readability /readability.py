# TODO

text = input("Text: ")

number_of_words = number_of_sentense = number_of_length = counter = 0
length = len(text)

while counter < length:
    if text[counter].isalpha():
        number_of_length += 1

    if (counter == 0 and text[counter] != " ") or (
        counter != length and text[counter] == " " and text[counter + 1] != " "
    ):
        number_of_words += 1

    if text[counter] == "?" or text[counter] == "." or text[counter] == "!":
        number_of_sentense += 1
    counter += 1

L = (number_of_length / number_of_words) * 100
S = (number_of_sentense / number_of_words) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
