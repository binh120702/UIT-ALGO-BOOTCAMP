#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
const int MOD = 1e9+7;
long long n, m, res=1;

long long    power2(long long k){
    if (k==0) return 1;
    long long tmp = power2(k/2);
    tmp = tmp*tmp % MOD;
    return k % 2 == 0 ? tmp : ((tmp*2) % MOD);
}

int     main()
{
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
    int t;
    cin >> t ;
    FOR(i,1,t)
    {
        long long a, b;
        cin >> a >> b;
        n = n + a + b;
        m = a*b;
        if (i<t) res = res * power2(m) % MOD;
        else res = res * power2(m-1) % MOD;
    }
    if (n % 2 == 1) cout << 0 ; else cout << res;

    return 0;
}

