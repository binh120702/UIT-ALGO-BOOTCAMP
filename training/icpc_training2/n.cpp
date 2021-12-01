#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define pb push_back
 
const int mn = 2e5 + 5;
 
using namespace std;
 
int n, m, same_character[25][25], cost_same_character[25][25], a[25][25];
string s[25];
 
void solve(){
    FOR(i,1,n)
    FOR(j,1,m){
        same_character[i][j] = 0;
        cost_same_character[i][j] = 0;
        int max_same_character=0;
        FOR(k,1,n) if (s[k][j]==s[i][j]){
            same_character[i][j] |= 1 << (k-1);
            cost_same_character[i][j] += a[k][j];
            max_same_character = max(max_same_character, a[k][j]);
        }
        cost_same_character[i][j] -= max_same_character;
    }
    int f[10000000];
    int max_mask = 1 << n;
    FOR(i,1,max_mask) f[i]=1000000000;
    f[0]=0;
    FOR(x,0,max_mask-1)
    FOR(j,1,n) if (!(x&(1<<(j-1)))&1){
        FOR(column,1,m) {
            f[x|(1<<(j-1))] = min(f[x|(1<<(j-1))], f[x]+a[j][column]);
            f[x|same_character[j][column]] = min(f[x|same_character[j][column]], f[x]+cost_same_character[j][column]);
        }
    }
    cout << f[max_mask-1];
}
 
int main(){
    cin >> n >> m;
    FOR(i,1,n) { cin >> s[i]; s[i]='1'+s[i]; };
    FOR(i,1,n) FOR(j,1,m) cin>>a[i][j];
    solve();
}