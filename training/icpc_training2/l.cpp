/**nhat-huy**/
#include <bits/stdc++.h>
using namespace std;

const int maxN = 3010;
int n, m, S1, T1, L1, S2, T2, L2;
vector<int> e[maxN];
int d[maxN][maxN], res;

void bfs(int S){
    for (int u=1; u<=n; ++u) d[S][u] = -1;
    d[S][S] = 0;
    deque<int> dq;
    dq.push_back(S);
    while (!dq.empty()){
        int u = dq.front(); dq.pop_front();
        for(int v: e[u])
        if (d[S][v] == -1){
            d[S][v] = d[S][u] + 1;
            dq.push_back(v);
        }
    }
}

void solve(){
    for(int u=1; u<=n; ++u) bfs(u);
    if (d[S1][T1] > L1 || d[S2][T2] > L2){
        cout << -1;
        return;
    }
    res = m - d[S1][T1] - d[S2][T2];
    for(int u=1; u<=n; ++u)
    for(int v=1; v<=n; ++v)
    if (d[S1][u] + d[u][v] + d[v][T1] <= L1 && d[S2][u] + d[u][v] + d[v][T2] <= L2){
        res = max(res, m - d[S1][u] - d[S2][u] - d[u][v] - d[v][T1] - d[v][T2]);
    }
    swap(S2, T2);
    for(int u=1; u<=n; ++u)
    for(int v=1; v<=n; ++v)
    if (d[S1][u] + d[u][v] + d[v][T1] <= L1 && d[S2][u] + d[u][v] + d[v][T2] <= L2){
        res = max(res, m - d[S1][u] - d[S2][u] - d[u][v] - d[v][T1] - d[v][T2]);
    }
    cout << res;
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; ++i){
        int u, v;
        cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    cin >> S1 >> T1 >> L1 >> S2 >> T2 >> L2;
    solve();
    return 0;
}
