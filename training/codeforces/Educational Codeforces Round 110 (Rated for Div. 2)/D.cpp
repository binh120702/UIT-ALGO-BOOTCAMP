// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

string s;
const int mn = 2e6 + 5;
int k,q,par[mn],lef[mn],rig[mn],n, f[mn];

void    dfsBuild(int u)
{
    if (lef[u]==0)
    {
        if (s[u] == '?') f[u]=2; else f[u]=1;
        return;
    }
    dfsBuild(lef[u]);
    dfsBuild(rig[u]);
    if (s[u]== '?') f[u] = f[lef[u]]+ f[rig[u]]; else
    if (s[u]== '0') f[u] = f[lef[u]]; else f[u] = f[rig[u]];
}

void    buildTree(){
    int node = 1; n = 1;

    FOR(i,1,k-1) node*=2;
    node+=1;

    FOR(i,1,k) n*=2;
    n-=1;

    s= '0'+s;
    int j = 1;
    while (node<=n){
        lef[node] = j;
        rig[node] = j+1;
        par[j] = node;
        par[j+1] = node;
        j+=2;
        node++;
    }
    dfsBuild(n);
}

void    update(int u)
{
    if (u==0) return;
    if (lef[u] == 0)
    {
        if (s[u]=='?') f[u] = 2; else f[u]= 1;
    } else
    {
        if (s[u]== '?') f[u] = f[lef[u]]+ f[rig[u]]; else
        if (s[u]== '0') f[u] = f[lef[u]]; else f[u] = f[rig[u]];
    }
    update(par[u]);
}

void	solve()
{
    buildTree();
    int pos;
    char c;
    while (q--)
    {
        cin >> pos >> c;
        s[pos] = c;
        update(pos);
        cout << f[n] << '\n';
    }
}

int 	main()
{
    cin>>k>>s>>q;
    solve();

	return 0;
}
