#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define pb push_back

const int mn = 2e5 + 5;
const int MD = 1e9 + 7;
using namespace std;
int n, visit[mn], mark[mn], node[mn];
long long f[mn], res[mn], remove_[mn];
vector<int> e[mn];
long long temp_mul[mn];
int cnt;
void dp_init(int u){
    visit[u] = 1;
    f[u] = 1;
    int l = cnt+1;
    for(int v: e[u]) if(!visit[v]){
        cnt++;
        mark[v] = cnt;
        node[cnt] = v;
    }
    int r = cnt;
    for(int v: e[u]) if(!visit[v]){
        dp_init(v);
        f[u] = (f[u] * (f[v]+1)) % MD;
    }
    temp_mul[0] = 1;
    FOR(i,1,r-l+1) temp_mul[i]=temp_mul[i-1]*(f[node[l+i-1]]+1) % MD;
    long long temp_mul_right = 1;
    for(int i = r-l; i>=0; i--) {
            remove_[node[l+i]] = temp_mul[i]*temp_mul_right % MD;
            temp_mul_right = temp_mul_right * (f[node[l+i]]+1) % MD;
    }
}

void root_rotate(int u, int par){
    visit[u] = 2;
    res[u] = f[u]*(f[par]+1) % MD;
    for(int v: e[u]) if (visit[v]<2){
        long long pre_fu = f[u];
        f[u] = (remove_[v] * (f[par]+1)) % MD;
        root_rotate(v, u);
        f[u] = pre_fu;
    }
}

void solve(){
    dp_init(1);
    root_rotate(1, 0);
    FOR(i,1,n) cout << res[i] << ' ';
}

int main(){
    cin >> n;
    FOR(i,2,n) {
        int p;
        cin >> p;
        e[p].pb(i);
        e[i].pb(p);
    }
    solve();
}

