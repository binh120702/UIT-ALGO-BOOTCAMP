n, m = map(int, input().split())
arr = [[int(j) for j in input().split()] for i in range(n)]

for i in range(1,n): 
    arr[i][0]+= arr[i-1][0]
for j in range(1,m):
    arr[0][j]+= arr[0][j-1]
for i in range(1,n):
    for j in range(1,m):
        arr[i][j]=arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]

def sum3x3(i, j):
    sum = arr[i][j]
    if (i-3>=0):
        sum-=arr[i-3][j]
    if (j-3>=0):
        sum-=arr[i][j-3]
    if (i>=3) & (j>=3):
        sum+=arr[i-3][j-3]
    return sum

minSum = 9*100000

for i in range(2,n):
    for j in range(2,m):
        minSum = min(minSum, sum3x3(i,j))

print(minSum)