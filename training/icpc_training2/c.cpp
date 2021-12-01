#include <bits/stdc++.h>

const int MAX_SIZE = 10000;
using namespace std;
double n, k, d, s;

void solve(){
    cin >> n >> k >> d >> s;
    double res = (d*n-s*k)/(n-k);
    if (res >= 0 && res <= 100) cout << fixed << setprecision(8) << res;
    else cout << "impossible";
}

int main(){
    solve();
}

