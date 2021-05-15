n, m, q = map(int, input().strip().split())
s = []
for i in range(n):
    s.append(input())
sol = [0]*10005
myMap = {}

for i in range(q):
    st = input()
    if not myMap.get(st):
        myMap[st] = []
    myMap[st].append(i)

for i in range(n):
    for j in range(m):
        # right
        cur_str = ''
        for step in range(10):
            if j+step>=m:
                break
            cur_str+=s[i][j+step]
            if myMap.get(cur_str) != None:
                for id in myMap[cur_str]:
                    sol[id] = 1
        # down
        cur_str = ''
        for step in range(10):
            if i+step>=n:
                break
            cur_str+=s[i+step][j]
            if myMap.get(cur_str) != None:
                for id in myMap[cur_str]:
                    sol[id] = 1
        
for i in range(q):
    print(sol[i], end='')