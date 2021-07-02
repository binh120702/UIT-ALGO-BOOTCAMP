#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define SET(a,x) memset((a),x,sizeof(a))

using namespace std;

typedef long long ll;

const int N=105;

int n,m;
char a[N][N];
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        cin >> n >> m;
        FOR(i,1,n)
            FOR(j,1,m)
            {
                cin >> a[i][j];
                if(a[i][j] == 'R') a[i][j] = 0;
                else if(a[i][j] == 'W') a[i][j] = 1;
                else a[i][j] = -1;
            }
        int kt1 = 1,kt2= 1;
        FOR(i,1,n)
        FOR(j,1,m)
        if((i+j) % 2 != a[i][j] && a[i][j] !=-1) kt1 = 0;
        FOR(i,1,n)
        FOR(j,1,m)
        if((i+j+1) % 2 != a[i][j] && a[i][j] !=-1) kt2 = 0;
        if(kt1)
        {
        cout << "YES" << '\n';
            FOR(i,1,n)
            {
                FOR(j,1,m) if((i+j) % 2 == 0) cout << "R";
                else cout << "W";
                cout << '\n';
            }
        }
        else
        if(kt2)
        {
            cout << "YES" << endl;
            FOR(i,1,n)
            {
                FOR(j,1,m) if((i+j+1) % 2 == 0) cout << "R";
                else cout << "W";
                cout << endl;
            }
        }
        else cout << "NO" << endl;
    }



}
