/*nhat-huy*/
#include <bits/stdc++.h>
using namespace std;

const int maxN = 110, maxS = 100000;
const int64_t oo = 1e15;
int n, Q, a[maxN];
int64_t f[maxS+1];

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> Q;
    for(int i=1; i<=n; ++i) cin >> a[i], f[i] = a[i];
    f[0] = 0;
    for(int i=n+1; i<=maxS; ++i){
        f[i] = oo;
        for(int j=1; j<=min(i-1, n); ++j)
            f[i] = min(f[i], f[j] + f[i-j]);
    }

    double gmin = oo;
    int imin = 0;
    for(int i=1; i<=n; ++i)
        if (1.0 * a[i] / i < gmin){
            gmin = 1.0 * a[i] / i;
            imin = i;
        }

    while (Q--){
        int K; cin >> K;
        int64_t res = 0;
        if (K > maxS){
            int temp = (K - maxS - 1) / imin + 1;
            res = 1LL * a[imin] * temp;
            K -= imin * temp;
        }
        res += f[K];
        cout << res << '\n';
    }
    return 0;
}
