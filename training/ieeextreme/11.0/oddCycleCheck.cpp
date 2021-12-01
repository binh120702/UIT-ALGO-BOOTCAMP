#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
int n;
const int mn = 2e4 + 4;
int pa[mn], pair_to[mn];

int findRoot(int u) {
    return pa[u] < 0 ? u : (pa[u] = findRoot(pa[u]));
}

void mergeSet(int u, int v) {
    if (!u || u==v) return;
    u = findRoot(u);
    v = findRoot(v);
    if (pa[u] < pa[v]) {
        pa[u] += pa[v];
        pa[v] = u;
    } else {
        pa[v] += pa[u];
        pa[u] = v;
    }
}

void solve(){
    FOR(i,1,n) pa[i] = -1, pair_to[i] = 0;

    while (1) {
        int u, v;
        cin >> u >> v;
        int x = findRoot(u);
        int y = findRoot(v);
        if (x == y)
        {
            cout << "0\n" ;
            return;
        }
        mergeSet(pair_to[x],y);
        mergeSet(pair_to[y],x);

        x = findRoot(u);
        y = findRoot(v);
        pair_to[x] = y;
        pair_to[y] = x;
        cout << "1\n" << flush;
    }
}

int     main()
{
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);

    cin >> n;
    solve();

    return 0;
}

