// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const int mn = 1000000;
int n,m, a[mn];

void    solve()
{
    a[n+1]=0;
    long long res=0;
    FOR(i,1,n)
    {
        if (a[i]>=a[i-1] && a[i]>=a[i+1]) {
            int x = min(a[i]-a[i-1], a[i]-a[i+1]);
            a[i]-= x;
            res+=x;
        }
    }
    FOR(i,1,n+1) res+=abs(a[i]-a[i-1]);
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
