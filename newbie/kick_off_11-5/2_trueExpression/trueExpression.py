n, s =map(int, input().split())

sum = (n*(n+1))//2

if (sum-s)%2==1 or sum<s:
    print('NO_SOLUTION ')
    exit()

tmp = (sum-s)//2
for i in range(1,n+1):
    tmp-=i
    if tmp<=0:
        for j in range(1,i+1):
            if j!=-tmp:
                print('-',end='')
            else: 
                print('+',end='')
        for j in range(i+1,n+1):
            print('+',end='')
        break