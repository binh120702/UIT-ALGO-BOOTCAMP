n, m = map(int, input().split())
a = [[int(0) for j in range(m)] for i in range(n)]
b = [[int(j) for j in input().split()] for i in range(n)]
ck = [0,0]

def nex(i,j):
    s= 0
    if i>0:
        s+=a[i-1][j]
    if i<n-1:
        s+=a[i+1][j]
    if j>0:
        s+=a[i][j-1]
    if j<m-1:
        s+=a[i][j+1]
    return s

def check():
    for i in range(1,n):
        for j in range(m):
            tmp = nex(i-1,j)-a[i][j]
            a[i][j] = b[i-1][j] - tmp
            if a[i][j]<0 or a[i][j]>2:
                return 0
            if nex(i-1,j)!=b[i-1][j]:
                return 0
    for i in range(n):
        for j in range(m):
            if nex(i,j)!=b[i][j]:
                return 0
    return 1

def pr():
    for i in range(n):
        for j in range(m):
            print(a[i][j], end = ' ')
        print()

def att(u, v):
    if ck[0] : 
        return
    for i in range(2):
        if ck[0] : 
            return
        a[u][v] = i
        if v>0 and b[u][v]-a[u][v-1]<0:
            continue
        if u==0 and v==m-1:
            ck[0] = check()
            if ck[0]:
                pr()
        else:
            if (u>0):
                att(u-1,v)
            else:
                att(u,v+1)



att(0,0)