// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

int     n, m,i,j;

long long dist(int i, int j, int u, int v){
    return abs(i-u) + abs(j-v);
}

void	solve()
{
    int x[4] = {1,1,n,n};
    int y[4] = {1,m,1,m};
    long long res = -1;
    int xk,xp;
    FOR(k,0,3)
    FOR(p,k,3)
    {
        long long dd = dist(x[k],y[k],i,j) + dist(x[k],y[k],x[p],y[p])
        + dist(x[p],y[p],i,j);
        if (dd>res){
            res = dd;
            xk = k;
            xp = p;
        }
    }
    cout << x[xk] << ' '<< y[xk] << ' ' << x[xp] << ' ' << y[xp] << '\n';
}

int 	main()
{
    int ts;
    cin>>ts;
    while (ts--){
        cin>>n>>m>>i>>j;
        solve();
	}
	return 0;
}
