#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
int s;
const int mn = 1e5 + 5;
const int MOD = 1e9 + 7;
long long f[2][mn], c[20][20];

void solve(){
    c[0][0] = 1;
    long long res = 0;
    FOR(i,1,17)
    {
        FOR(j,1,i) c[i][j] = c[i-1][j] + c[i-1][j-1];
        FOR(j,1,s) f[1][j] = 0;
        f[1][0] = 1;
        FOR(j,1,i) {
            FOR(w,0,s)
                f[0][w] = f[1][w];
            FOR(w,0,s-c[i][j])
                f[0][w+c[i][j]] += f[0][w];
            FOR(w,0,s)
                f[1][w] = (f[0][w] - f[1][w] + MOD) % MOD;
        }
        res = (res + f[1][s]) % MOD;
    }
    cout << res;
}

int     main()
{
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);

    cin >> s;
    solve();

    return 0;
}

