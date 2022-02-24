tot = 1
for i in range(int(input())):
    tot = (tot * int(input())) % 1000
print(tot)