#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
const int mn =1e5+5;
int n;
string s;
char b[5] = {'1','4','6','8','9'};
int c[4] = {2, 3, 5, 7};

void    solve()
{
    s='4'+s;
    FOR(i,1,n)
    FOR(j,0,4) if (b[j]==s[i])
    {
        cout << 1 << '\n' << s[i] << '\n';
        return;
    }
    int dd[10];
    int pairs[10][10];
    FOR(i,1,9) dd[i] = 0;
    FOR(i,1,9)
    FOR(j,1,9) pairs[i][j]=0;
    FOR(i,1,n)
    {
        int dg = s[i]-'0';
        FOR(j,0,3) if (dd[c[j]]) pairs[c[j]][dg] = 1;
        dd[dg]=1;
    }
    cout << "2\n";
    if (pairs[2][5])
    {
        cout << "25";
    } else
    if (pairs[2][7])
    {
        cout << "27";
    } else
    if (pairs[2][2])
    {
        cout << "22";
    } else
    if (pairs[3][2])
    {
        cout << "32";
    } else
    if (pairs[3][3])
    {
        cout << "33";
    } else
    if (pairs[3][5])
    {
        cout << "35";
    } else
    if (pairs[5][2])
    {
        cout << "52";
    } else
    if (pairs[5][5])
    {
        cout << "55";
    } else
    if (pairs[5][7])
    {
        cout << "57";
    } else
    if (pairs[7][2])
    {
        cout << "72";
    } else
    if (pairs[7][5])
    {
        cout << "75";
    } else
    if (pairs[7][7])
    {
        cout << "77";
    } ;
    cout << '\n';
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
