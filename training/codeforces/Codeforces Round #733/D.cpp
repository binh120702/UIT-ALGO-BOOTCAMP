#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
string s;
const int mn = 200005;
int n, nex[mn], din[mn], visited[mn], root, outlist[mn], cnt, pnex[mn], change_one;

void    dfs(int u)
{
    visited[u] = 1;
    if (!visited[nex[u]])
    {
        dfs(nex[u]);
    } else
    {
        if (root==u) outlist[++cnt] = root; else
        {
            nex[u] = root;
            if (change_one == 0) change_one = u;
        }
    }
}

void    solve()
{
    FOR(i,1,n) din[nex[i]]++, pnex[i]=nex[i];
    cnt = 0;
    change_one = 0;
    FOR(i,1,n) if (din[i] == 0)
    {
        root = i;
        dfs(i);
    }
    FOR(i,1,n) if (!visited[i])
    {
        root = i;
        dfs(i);
    }
    if (cnt == 1)
    {
        int pp = nex[change_one];
        nex[change_one] = outlist[1];
        nex[outlist[1]] = pp;
    } else
    {
        FOR(i,1,cnt-1) nex[outlist[i]] = outlist[i+1];
        nex[outlist[cnt]] = outlist[1];
    }
    int res=0;
    FOR(i,1,n) res+= (pnex[i]==nex[i]);
    cout << res << '\n';
    FOR(i,1,n) cout << nex[i] << ' ';
    cout << '\n';
    FOR(i,1,n) visited[i] = din[i] = 0;
}

int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        cin >> n;
        FOR(i,1,n) cin >> nex[i];
        solve();
    }
}
