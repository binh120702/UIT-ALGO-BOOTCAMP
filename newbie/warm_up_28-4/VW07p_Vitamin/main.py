ss = input().strip().split()
n = int(ss[0])
x = int(ss[1])
arr = [int(i) for i in input().split()]

for i in range(1,n-1):
    arr[i] = arr[i]+arr[i-1]
    
f = [-1]*(x+5) 
f[0] =  0

for i in range(n-1):
    for j in range(arr[i],x+1):
        if f[j-arr[i]]!=-1:
            if (f[j]==-1) or (f[j-arr[i]]+i+2<f[j]):
                f[j] = f[j-arr[i]]+i+2

sol = f[x]

if n>1:
    for i in range(x-arr[n-2]+1):
        if (f[i]!=-1) and ((x-i-arr[n-2])%arr[n-1]==0):
            if (sol==-1) or (sol>f[i]+n+(x-i-arr[n-2])//arr[n-1]):
                sol = f[i]+n+(x-i-arr[n-2])//arr[n-1]

if sol>0:
    print(sol-1)
else:
    print(sol)