/*nhat-huy*/
#include <bits/stdc++.h>
using namespace std;

const int maxN = 410;
int n, d[maxN], t[3][maxN];
pair<int, int> visitTime[3][maxN][maxN];
bool e01[maxN][maxN], e02[maxN][maxN], e12[maxN][maxN];

void enter(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> d[i];
    for(int i=0; i<=2; ++i)
        for(int j=1; j<=n; ++j) cin >> t[i][j];
}

bool intersect(pair<int, int> p1, pair<int, int> p2){
    if (p1.second <= p2.first) return false;
    if (p2.second <= p1.first) return false;
    return true;
}

void init(){
    for(int human = 0; human <= 2; ++human)
    for(int src=1; src<=n; ++src){
        int u = src, nexu = u % n + 1;
        visitTime[human][src][u] = {0, t[human][src]};
        while (nexu != src) {
            visitTime[human][src][nexu].first = visitTime[human][src][u].second + d[u];
            visitTime[human][src][nexu].second = visitTime[human][src][nexu].first + t[human][nexu];
            u = nexu;
            nexu = u % n + 1;
        }
    }

    /*
    for(int human=0; human<3; ++human){
        cout << human << '\n';
        for(int u=1; u<=n; ++u){
            for(int v=1; v<=n; ++v)
                cout << visitTime[human][u][v].first << ',' << visitTime[human][u][v].second << "  ";
            cout << '\n';
        }
    }
    */

    for(int u=1; u<=n; ++u)
    for(int v=1; v<=n; ++v){
        bool check = true;
        for(int i=1; i<=n; ++i)
        if (intersect(visitTime[0][u][i], visitTime[1][v][i])){
            check = false;
            break;
        }
        if (check) e01[u][v] = true; else e01[u][v] = false;
    }

    for(int u=1; u<=n; ++u)
    for(int v=1; v<=n; ++v){
        bool check = true;
        for(int i=1; i<=n; ++i)
        if (intersect(visitTime[0][u][i], visitTime[2][v][i])){
            check = false;
            break;
        }
        if (check) e02[u][v] = true; else e02[u][v] = false;
    }

    for(int u=1; u<=n; ++u)
    for(int v=1; v<=n; ++v){
        bool check = true;
        for(int i=1; i<=n; ++i)
        if (intersect(visitTime[1][u][i], visitTime[2][v][i])){
            check = false;
            break;
        }
        if (check) e12[u][v] = true; else e12[u][v] = false;
    }
}

void solve(){
    for(int u=1; u<=n; ++u)
    for(int v=1; v<=n; ++v)
    if (e01[u][v])
        for(int i=1; i<=n; ++i)
        if (e02[u][i] && e12[v][i]){
            cout << u << ' ' << v << ' ' << i;
            return;
        }
    cout << "impossible";
}

int main()
{
    enter();
    init();
    solve();
    return 0;
}
