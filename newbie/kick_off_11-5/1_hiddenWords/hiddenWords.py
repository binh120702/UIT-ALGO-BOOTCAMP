n, m, q = map(int, input().strip().split())
s = []
for i in range(n):
    s.append(input())
tree = [[0 for i in range(26)] for j in range(n*m*10+10)]


cnt = 1
def add(pos, s):
    global cnt
    val = ord(s)-ord('a')
    if tree[pos][val]!=0:
        return tree[pos][val]
    cnt+=1
    tree[pos][val]=cnt
    return cnt

for i in range(n):
    for j in range(m):
        cur_pos = add(1,s[i][j])
        for k in range(1,10):
            if i+k>=n: 
                break
            cur_pos = add(cur_pos, s[i+k][j])

        cur_pos = add(1,s[i][j])
        for k in range(1,10):
            if j+k>=n:
                break
            cur_pos = add(cur_pos, s[i][j+k])

def check_if_exist(s):
    cur = 1
    for chr in s:
        val = ord(chr)-ord('a')
        if tree[cur][val]==0:
            return 0
        cur = tree[cur][val]
    return 1

for i in range(q):
    txt = input()
    print(check_if_exist(txt),end='')