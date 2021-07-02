// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

int     n, a[100000];

void	solve()
{
    int sum=0;
    FOR(i,1,n) sum+=a[i];
    if (sum>=n)
    {
        cout << sum-n << '\n';
    } else
    {
        cout << 1 << '\n';
    }
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
