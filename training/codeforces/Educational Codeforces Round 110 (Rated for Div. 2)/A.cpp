// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

int a,b,c,d;

void	solve()
{
    if (min(a,b)>max(c,d) || max(a,b)<min(c,d)) cout << "NO\n"; else cout << "YES\n";
}

int 	main()
{
    int ts;
    cin>>ts;
    while (ts--){
            cin>>a>>b>>c>>d;
	solve();
    }

	return 0;
}
