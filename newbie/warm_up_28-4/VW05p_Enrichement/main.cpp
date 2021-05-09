#include <bits/stdc++.h>
using namespace std;
int     n,m,a[1000001];

int get_value(int i, int j)
{
    return a[(i-1)*m+j];
}

int main() {
    cin>>n>>m;
    int cnt = 0,x;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++) 
    {
        cin>>x;
        a[++cnt]=x;
    }
    
    int minSum=9*100000;
    for (int i=1; i<=n-2; i++)
    for (int j=1; j<=m-2; j++) {
        int tmp_sum=0;
        for (int x=0; x<=2; x++)
            for (int y=0; y<=2; y++) tmp_sum+=get_value(i+x,j+y);
        minSum = min(minSum, tmp_sum);
    }
    cout << minSum;
}