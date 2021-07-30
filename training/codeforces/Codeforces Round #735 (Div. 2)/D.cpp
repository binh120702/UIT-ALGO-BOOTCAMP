#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
int n;
void solve()
{
    if (n==1)
    {
        cout<<"a\n";return;
    }
    int y = n/2;
    int x = y-1;
    FOR(i,1,x) cout << 'a';
    FOR(i,1,n-x-y) cout << char((int)('a')+i);
    FOR(i,1,y) cout << 'a';
    cout << '\n';
}

int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        cin >> n;
        solve();
    }
}
