from random import randint


ntestes = randint(1,30)

f = open("randtest.txt", "w")
f.write(f"{ntestes}\n")
for i in range(ntestes):
    cols = randint (2,60)
    rows = randint (2, 60)
    f.write(f"{rows} {cols}\n")
    for i in range(rows):
        for j in range(cols):
            if (i == 0 and j == 0):
                f.write(f"{0} ")
            elif(i==rows-1 and j==cols-1):
                f.write(f"{0} ")
            else:
                f.write(f"{randint(-100, 100)} ")
        f.write("\n")