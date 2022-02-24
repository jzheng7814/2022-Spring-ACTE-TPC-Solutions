amt = int(input())
tot = 0

for i in (25, 10, 5, 1):
    tot += amt // i
    amt %= i

print(tot)