#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int mn = 1e3 + 5;
int n, m, k, f[mn*3][mn*3], r[mn*mn], c[mn*mn], d[mn*mn], res[mn*mn];
const int MX = 1000;

void add(int i, int j, int x)
{
    if (i<2) i = 2;
    if (j<1-m+MX) j = 1-m+MX;
    if (i>n+m) return;
    if (j>n-1+MX) return;

    f[i][j] += x;
}

void solve(){
    FOR(i,1,k)
    {
        int new_row = r[i]+c[i];
        int new_col = r[i]-c[i]+MX;
        add(new_row-d[i], new_col-d[i], 1);
        add(new_row-d[i], new_col+d[i]+1, -1);
        add(new_row+d[i]+1, new_col-d[i], -1);
        add(new_row+d[i]+1, new_col+d[i]+1, 1);
    }
    FOR(i,2,n+m)
    FOR(j,1-m+MX,n-1+MX)
        f[i][j] += f[i][j-1] + f[i-1][j] - f[i-1][j-1];
    int maxPos = 0;
    FOR(i,1,k)
    {
        int rr = r[i]+c[i];
        int cc = r[i]-c[i]+MX;
        res[i] = f[rr][cc];
        if (res[i] > res[maxPos]) maxPos = i;
    }
    cout << maxPos << ' ' << res[maxPos]-1;
}


int     main(){
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);

    cin >> n >> m >> k;
    FOR(i,1,k) cin >> r[i] >> c[i] >> d[i];

    solve();

    return 0;
}

