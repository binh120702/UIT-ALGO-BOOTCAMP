n = int(input())
a = [int(s) for s in input().split()]

sum = 0
ans = -1
for i in a:
    sum+=i
if (sum%2==1):
    print(0)
    exit()

dp = 1 
for i in a:
    dp|=(dp<<i)
if ((dp>>(sum>>1))&1)== 0:
    print(0)
    exit()

cur_min = 100
ans = 0
for i in range(n):
    cnt_div_2 = 0
    while a[i]%2==0:
        cnt_div_2+=1
        a[i]=a[i]//2
    if cnt_div_2 < cur_min:
        cur_min = cnt_div_2
        ans = i
print(1)
print(ans+1)