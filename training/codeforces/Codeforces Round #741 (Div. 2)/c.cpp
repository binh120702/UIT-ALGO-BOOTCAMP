#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
const int mn =1e5+5;
int n;
string s;

void    solve()
{
    s = '1'+s;
    int pos = -1;
    FOR(i,1,n)
    {
        if (s[i]=='0')
        {
            pos = i;
        }
    }
    if (pos == -1)
    {
        cout << 1 << ' ' << n/2 << ' '<< n-n/2+1 <<' '<< n <<'\n';
    } else
    if (pos <= n/2)
    {
        cout << pos << ' ' << n << ' ' << pos+1 << ' ' << n << '\n';
    } else
    cout << 1 << ' ' << pos << ' ' << 1 << ' ' << pos-1 << '\n';
}

int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        cin >> n >> s;
        solve();
    }
}
