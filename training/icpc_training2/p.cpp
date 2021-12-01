#include <bits/stdc++.h>
#define F(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

const int maxn = 1010;

int n, a[maxn][maxn], t1[maxn][maxn], t2[maxn][maxn], m2[maxn][maxn], m5[maxn][maxn], zx, zy;
bool zero = false;

int main()
{
    
    cin >> n;
    F(i,1,n) F(j,1,n)
    {
        cin >> a[i][j];
        int x = a[i][j];
        if (x == 0)
        {
            x = 10;
            zero = true;
            zx = i; zy = j;
        }
        while (x % 2 == 0 && x > 1)
        {
            m2[i][j]++;
            x/=2;
        }
        while (x % 5 == 0 && x > 1)
        {
            m5[i][j]++;
            x/=5;
        }
    }

    F(i,0,n)
    {
        m2[i][0] = 99999;
        m2[0][i] = 99999;
        m5[i][0] = 99999;
        m5[0][i] = 99999;
    }

    F(i,1,n)
    F(j,1,n)
    {
        if (i == 1 && j == 1) continue;
        if (m2[i-1][j] < m2[i][j-1])
        {
            m2[i][j] += m2[i-1][j];
            t1[i][j] = -1;
        }
        else
        {
            m2[i][j] += m2[i][j-1];
            t1[i][j] = 1;
        }

        if (m5[i-1][j] < m5[i][j-1])
        {
            m5[i][j] += m5[i-1][j];
            t2[i][j] = -1;
        }
        else
        {
            m5[i][j] += m5[i][j-1];
            t2[i][j] = 1;
        }
    }

    if (zero)
    {
        if (min(m2[n][n], m5[n][n]) > 1)
        {
            cout << "1\n";
            F(i,1,zy-1) cout << "R";
            F(i,1,zx-1) cout << "D";
            F(i,1,n-zy) cout << "R";
            F(i,1,n-zx) cout << "D";
            return 0;
        }
    }

    cout << min(m2[n][n], m5[n][n]) << '\n';

    if (m5[n][n] < m2[n][n])
        F(i,1,n) F(j,1,n) t1[i][j] = t2[i][j];

    int i = n, j = n;
    char ans[maxn*maxn];
    int nans = 0;

    while (!(i == 1 && j == 1))
    {
        if (t1[i][j] == -1)
        {
            ans[++nans] = 'D';
            i-=1;
        }
        else
        {
            ans[++nans] = 'R';
            j-=1;
        }
    }

    for (int i = nans; i >= 1; i--)
        cout << ans[i];

    return 0;
}
