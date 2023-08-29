# TODO
while True:
    try:
        h = int(input("Height: "))
        if h >= 1 and h <= 8:
            break
    except:
        pass
s = 1
# prints newline
for j in range(h):
    # prints s
    for s in range(h - j - 1):
        print(" ", end="")

    # prints hashes
    for i in range(j + 1):
        print("#", end="")
    print()
