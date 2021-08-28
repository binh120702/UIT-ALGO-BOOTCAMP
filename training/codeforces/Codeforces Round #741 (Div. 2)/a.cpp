#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
const int mn =1e5+5;
int n, l,r;

void    solve()
{
    int best = (r+1)/2 + 1 - (r%2);
    cout << r % max(l,best) << '\n';
}

int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        cin >> l >> r;
        solve();
    }
}
