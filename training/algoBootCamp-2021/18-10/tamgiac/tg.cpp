#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int mn = 2e5 + 5;
int n, l, a[mn];

void solve(){
    sort(a+1,a+1+n);
    FOR(i,1,n) a[i+n] = a[i]+l;
    int j = 2;
    long long res = 0;
    FOR(i,1,n){
        while (2*(a[j]-a[i])<=l) j++;
        res += (j-i-1)*(n-(j-i-1)-1);
    }
    cout << res / 3;
}


int     main(){
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);

    cin >> n >> l;
    FOR(i,1,n) cin >> a[i];
    solve();

}

