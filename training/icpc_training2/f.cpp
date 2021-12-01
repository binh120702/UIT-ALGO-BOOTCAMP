#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define double long double
const int mn = 2e5 + 5;
using namespace std;
int n, x[mn], v[mn];

priority_queue<pair<double, pair<int, int>> > q;

void push(int l, int r){
    if (l==0 || r==n+1) return;
    double x1 = x[l];
    double x2 = x[r];
    double d = x[r]-x[l];
    double v1 = v[l];
    double v2 = v[r];

    if (v1 > v2){
        q.push({-d / (v1 - v2), {l, r}});
    }
}

int destroyed[mn], pre[mn], nex[mn];

void solve(){
    FOR(i,1,n){
        pre[i] = i-1;
        nex[i] = i+1;
        push(i-1, i);
        push(i, i+1);
    }
    while (!q.empty()){
        while (!q.empty() && (destroyed[q.top().second.first] || destroyed[q.top().second.second]))
            q.pop();
        if (q.empty()) break;
        int u = q.top().second.first;
        int v = q.top().second.second;
        q.pop();
        destroyed[u] = 1;
        destroyed[v] = 1;
        int new_u = pre[u];
        int new_v = nex[v];
        while (destroyed[new_u]) new_u = pre[new_u];
        while (destroyed[new_v]) new_v = nex[new_v];
        nex[new_u] = new_v;
        pre[new_v] = new_u;
        push(new_u, new_v);
    }
    int res= 0;
    FOR(i,1,n) if (!destroyed[i]) res++;
    cout << res << '\n';
    FOR(i,1,n) if (!destroyed[i]) cout << i << ' ';
}

int main(){
    cin >> n;
    FOR(i,1,n) cin >> x[i] >> v[i];
    solve();
}

