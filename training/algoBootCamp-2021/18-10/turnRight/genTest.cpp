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

void solve(int ts){
    ofstream fo(("output"+to_string(ts)+".txt").c_str());
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

    FOR(i,1,n)
    FOR(j,1,m)
    FOR(k,0,3) dist[i][j][k] = 0;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(sx, sy, k));
    dist[sx][sy][k] = 1;
    while (!q.empty()){
        tuple<int, int, int> u = q.front(); q.pop();
        int x = get<0>(u);
        int y = get<1>(u);
        int k = get<2>(u);
        if (x == tx && y == ty){
            fo << dist[x][y][k] - 1;
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
    fo << -1;
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int Rand(int l, int h) {
    assert(l <= h);
    return l + (rd() % (h - l + 1));
}

int     vis[mn][mn][4], f[mn][mn];

bool    inRange(int x, int y, int k){
    return x && x<=n && y && y<=m && !vis[x][y][k];
}

int    randomDfs(int u, int v, int k, int tx, int ty){
    if (u == tx && v == ty) return 1;
    vis[u][v][k] = 1;
    int coin = Rand(1,2);
    if (coin == 1){
        FOR(dd,0,1){
            int kk = (k+dd)%4;
            int uu = u + dx[kk];
            int vv = v + dy[kk];
            if (inRange(uu,vv,kk)) {
                int ff = randomDfs(uu,vv,kk,tx,ty);
                if (ff>0) {
                    f[u][v] = 1;
                    return 1;
                }
            }
        }
    } else{
        FORD(dd,1,0){
            int kk = (k+dd)%4;
            int uu = u + dx[kk];
            int vv = v + dy[kk];
            if (inRange(uu,vv,kk)) {
                int ff = randomDfs(uu,vv,kk,tx,ty);
                if (ff>0) {
                    f[u][v] = 1;
                    return 1;
                }
            }
        }
    }

    return 0;
}

void    createTest(int ctest){
    ofstream fo(("input"+to_string(ctest)+".txt").c_str());
    char a[mn][mn];
    const int PERCENT = 75;
    n = Rand(1000, 1000);
    m = Rand(1000, 1000);
    FOR(i,1,n)
        FOR(j,1,m) a[i][j] = '.', f[i][j] = 0;
    FOR(i,1,n)
        FOR(j,1,m)
            FOR(k,1,4) vis[i][j][k] = 0;

    int u = Rand(2,n-1);
    int v = Rand(2,m-1);
    int k = Rand(0,3);
    a[u][v] = dir[k];

    int tx = u;
    int ty = v;
    while (tx == u && ty == v){
        tx = Rand(1,n);
        ty = Rand(1,m);
    }
    a[tx][ty] = 'D';
    int tmp = randomDfs(u,v,k,tx,ty);
    f[tx][ty] = 1;
    FOR(i,1,n)
    FOR(j,1,m) if (f[i][j]==0) {
        int x = Rand(1,100);
        if (x <= PERCENT) a[i][j] = '#';
    }
    fo << n << ' ' << m << '\n';
    FOR(i,1,n){
        FOR(j,1,m) fo << a[i][j] ; fo << '\n';
    }
    fo.close();
}


int     main(){
    int NTEST = 20;
    FOR(ts, 16, NTEST){
        createTest(ts);
        ifstream fi(("input"+to_string(ts)+".txt").c_str());
        fi >> n >> m;
        FOR(i,1,n) fi >> (a[i]+1);
        solve(ts);
    }
}

