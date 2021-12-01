#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int mn = 105;
int n, m, r, c;
char a[mn][mn], b[mn][mn];

void solve(){
    int res = 0;
    FOR(i,1,r-n+1){
        FOR(j,1,c-m+1){
            int cmp = 1;
            FOR(x,1,n) if (cmp)
            FOR(y,1,m)
            if (b[x][y] != a[i+x-1][j+y-1] && b[x][y]!='?') cmp = 0;
            if (cmp == 1) res++;
        }
    }
    cout << res << '\n';
}

int main()
{
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int ts;
    cin >> ts;
    while (ts--){
        cin >> r >> c;
        FOR(i,1,r) cin >> (a[i]+1);
        cin >> n >> m;
        FOR(i,1,n) cin >> (b[i]+1);
        solve();
    }
    return 0;
}
