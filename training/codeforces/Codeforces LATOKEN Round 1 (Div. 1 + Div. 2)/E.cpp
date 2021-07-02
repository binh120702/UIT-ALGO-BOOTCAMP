// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

int n,k,res,cur;
bool    f[10000], visit[10000];
int typ[10000], trace[10000],st[5000];
bool     dp(int u){
    if (visit[u]) return f[u];
    visit[u] = 1;
    st[u] = 555;
    if (u>=k && dp(u-k) && st[u-k]+1<st[u])
    {
        f[u] = 1;
        typ[u] = 1;
        st[u] = st[u-k]+1;
    }
    for(int j=2; j<=u; j+=2)
    if (j/2<=k && j/2+k<=n && dp(u-j) && st[u-j]+1<st[u]) {
        f[u] = 1;
        typ[u] = 2;
        trace[u] = j;
        st[u] = st[u-j]+1;
    }
    return f[u];
}

void     get(int u){
    if (u==0) return;
    if (typ[u]==1){
        cout<<"? ";
        FOR(j,cur,cur+k-1)
        {
            cout << j << ' ';
        }
        cur+=k;
        cout << '\n';
        fflush(stdout);
        int x;
        cin >> x;
        res = res ^ x;
        get(u-k);
    } else
    {
        cout<<"? ";
        int nex = cur+(trace[u]/2)-1;
        FOR(j,cur,nex) cout << j << ' ';
        int cnt = trace[u]/2;
        FOR(j,1,n) {
            if (cnt==k) break;
            if (j<cur || j>cur+trace[u]-1) {
                cout << j << ' ';
                cnt++;
            }
        }
        cout << '\n';
        fflush(stdout);
        int x;
        cin >> x;
        res = res ^ x;

        cout<<"? ";
        int nex2 = nex+(trace[u]/2);
        FOR(j,nex+1,nex2) cout << j << ' ';
        cnt = trace[u]/2;
        FOR(j,1,n) {
            if (cnt==k) break;
            if (j<cur || j>cur+trace[u]-1) {
                cout << j << ' ';
                cnt++;
            }
        }
        cout << '\n';
        fflush(stdout);
        cin >> x;
        res = res ^ x;
        cur+=trace[u];
        get(u-trace[u]);
    }
}

void    solve()
{
    f[0] = true;
    st[0]=0;
    visit[0] = 1;
    FOR(i,1,n) f[i] = false;
    if (!dp(n)){
        cout << -1; return;
    }
    cur=1;
    get(n);
    cout << "! " << res;
}

int 	main()
{
    cin>>n>>k;
    solve();
	return 0;
}
