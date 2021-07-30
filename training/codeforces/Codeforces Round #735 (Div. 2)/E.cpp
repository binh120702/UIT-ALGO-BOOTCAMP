#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
const int mn = 1e5 + 5, mod = 998244353;
int n, val, d[mn], noRes, a[mn], res[mn];
vector<int> e[mn];

void    dfs(int u)
{
    d[u] = 1;
    if (noRes) return;
    for(int v: e[u]) if (d[v]==0)
    {
        dfs(v);
        if (d[v] == 1) a[u]++;
    }
    if (a[u]%val!=0) { a[u]++; d[u] = 2;}
    if (a[u]%val!=0 || (u == 1 && d[u] == 2)) noRes = 1;
}

void    solve()
{
    res[1] = 1;
    FOR(i,1,n-1) res[1] = res[1]*2 % mod;
    FOR(i,2,n) res[i] = 0;
    FOR(i,2,n-1) if ((n-1)%i==0)
    {
        FOR(k,1,n) a[k] = d[k] = 0;
        noRes = 0;
        val = i;
        dfs(1);
        res[i] = 1 - noRes;
    }
    FORD(i,n/2,1)
        for(int j = i + i; j<=n; j+=i)
        res[i] = (res[i] - res[j] + mod) % mod;

    FOR(i,1,n) cout << res[i] << ' '; cout << '\n';
    FOR(i,1,n) e[i].clear();
}

int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        cin >> n;
        FOR(i,1,n-1)
        {
            int u,v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        solve();
    }
}
