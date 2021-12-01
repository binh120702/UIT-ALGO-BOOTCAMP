#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int mn = 1e3 + 5;
int n, m, dist[mn][mn][4];
char a[mn][mn];
const char dir[4] = {'E', 'S', 'W', 'N'};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool    legit(int x, int y, int k){
    return 1<=x && x<=n && 1<=y && y<=m && !dist[x][y][k] && a[x][y]!='#';
}

void solve(){
    int sx, sy, tx, ty;
    FOR(i,1,n)
    FOR(j,1,m) if (a[i][j] == 'D') {
        tx = i;
        ty = j;
    } else
    if (a[i][j] != '.' && a[i][j] != '#') {
        sx = i;
        sy = j;
    }
    int k;
    FOR(i,0,3) if (dir[i] == a[sx][sy]) k = i;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(sx, sy, k));
    dist[sx][sy][k] = 1;

    while (!q.empty()){
        tuple<int, int, int> u = q.front(); q.pop();
        int x = get<0>(u);
        int y = get<1>(u);
        int k = get<2>(u);
        if (x == tx && y == ty){
            cout << dist[x][y][k] - 1;
            return;
        }
        // go ahead
        int k1 = k;
        int x1 = x + dx [k1];
        int y1 = y + dy[k1];
        if (legit(x1,y1,k1)){
            q.push(make_tuple(x1, y1, k1)) ;
            dist[x1][y1][k1] = dist[x][y][k]+1;
        }

        // turn right
        int k2 = (k+1)%4;
        int x2 = x + dx[k2];
        int y2 = y + dy[k2];
        if (legit(x2,y2,k2)){
            q.push(make_tuple(x2, y2, k2)) ;
            dist[x2][y2][k2] = dist[x][y][k]+1;
        }
    }
    cout << -1;
}


int     main(){
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);

    cin >> n >> m;
    FOR(i,1,n) cin >> (a[i]+1);
    solve();

}

