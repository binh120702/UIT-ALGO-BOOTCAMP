// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

int a[10000], n;

void	solve()
{
    int b[5000];
    int m=0;
    FOR(i,1,n) if (a[i]%2==0) b[++m] = a[i];
    FOR(i,1,n) if (a[i]%2==1) b[++m] = a[i];
    int res = 0;
    FOR(i,1,n-1)
    FOR(j,i+1,n) if (b[i]%2==0) res++; else
    {
        int uc = __gcd(b[i], b[j]);
        if (uc>1) res++;
    }
    cout << res << '\n';
}

int 	main()
{
    int ts;
    cin>>ts;
    while (ts--){
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        solve();
    }

	return 0;
}
