#include<bits/stdc++.h>
using namespace std;

int n, MAXX;
int a[110], d[1000010];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> MAXX;
    for(int i=1; i<=n; ++i) cin >> a[i], a[i]+=a[i-1];
    a[n]-=a[n-1];


    for(int x=0; x<=MAXX; ++x) d[x]=1e9;
    d[0]=0;

    for(int i=1; i<=n-1; ++i)
        for(int x=a[i]; x<=MAXX; ++x)
            d[x]=min(d[x], d[x-a[i]]+i+1);

    for(int x=0; x<=MAXX-a[n-1]; ++x)
        if ((MAXX-x-a[n-1])%a[n]==0) d[MAXX]=min(d[MAXX], d[x]+(MAXX-x-a[n-1])/a[n]+n);

    if (d[MAXX]==1e9) cout << -1; else cout << d[MAXX]-1;
}