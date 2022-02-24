N, K = [int(i) for i in input().split()]
classdict = {}

for i in range(1, N + 1):
    classdict[i] = []

for i in range(K):
    rec = input().split()
    rec[3] = int(rec[3])
    rec[0] = int(rec[0])

    classdict[rec[0]].append(rec[1:])

for i in range(1, N + 1):
    classrecs = classdict[i]
    classrecs = sorted(sorted(sorted(classrecs, key = lambda i: i[2], reverse = True), key = lambda i: i[0]), key = lambda i: i[1])
    
    newclassrecs = []

    k = 0
    while k < len(classrecs):
        ini = k
        newclassrecs.append(classrecs[ini])
        while k < len(classrecs) and classrecs[ini][0] + classrecs[ini][1] == classrecs[k][0] + classrecs[k][1]:
            k += 1 
    
    for j in newclassrecs:
        print(f'{i} {j[0]} {j[1]} {j[2]}')
