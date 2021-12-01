#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)

const int mn = 2e5 + 5;
using namespace std;
int n, t[mn], res[mn];

void solve(){
    sort(t+1, t+1+n);
    int cur = 0;
    if (n%2) res[++cur] = t[(n+1)/2];
    int l = n/2;
    int r = (n+1)/2 + 1;
    while (l){
        res[++cur] = t[l--];
        res[++cur] = t[r++];
    }
    FOR(i,1,n) cout << res[i] << ' ';
}

int main(){
    cin >> n;
    FOR(i,1,n) cin >> t[i];
    solve();
}

