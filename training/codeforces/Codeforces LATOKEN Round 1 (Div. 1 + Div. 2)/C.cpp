// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const int mn = 1000000;
int n, a[2][mn], visit[mn], pos[2][mn];

void    dfs(int j){
    if (visit[j]) return;
    visit[j] = 1;
    dfs(pos[0][a[1][j]]);
}

void    solve()
{
    FOR(i,1,n) visit[i]=0;
    long long res=1;
    FOR(i,1,n) if (!visit[i]) {dfs(i); res=(res*2)%(1000000007);};
    cout << res << '\n';
}

int 	main()
{
    int ts;
    cin>>ts;
    while (ts--){
            cin>>n;
    FOR(j,0,1)
    FOR(i,1,n)
    {
        cin>>a[j][i];
        pos[j][a[j][i]] = i;
    }
    solve();
    }
	return 0;
}
