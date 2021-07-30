#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
const int MOD = 31607;
const int mn = 25;
inline int mul(int u, int v) { return (long long)u*v % MOD; }
inline int sub(int u, int v) { return (u-=v) <0 ? u+MOD : u; }
inline int add(int u, int v) { return (u+v) % MOD;}
inline int power(int u, int v) {
    int res = 1;
    for(; v; v>>=1, u = mul(u,u))
        if (v&1) res= mul(res,u);
    return res;
}
inline int inv(int u) { return power(u, MOD-2); }
inline int get_bit(int u, int k) { return (u >> (k-1)) & 1;}
inline int set0(int u, int k) { return u & (~(1<<(k-1)));}
const int MAU = 10000;
const int INV_MAU = inv(MAU);


int n, a[mn][mn], t[mn][mn];


int    process()
{
    int aa[mn][mn];
    FOR(i,0,n-1)
    FOR(j,0,n-1) aa[i][j]=t[i+1][j+1];

    static int dp[1 << mn], dq[1 << mn], dr[1 << mn];
	int i, j, b, ans;

	for (b = 0; b < 1 << n; b++)
		dq[b] = 1;
	dr[0] = 1;
	for (j = 0; j < n; j++)
		dr[1 << j] = -1;
	for (i = 0; i < n; i++) {
		dp[0] = 1;
		for (j = 0; j < n; j++)
			dp[1 << j] = aa[i][j], dr[1 << j] = dr[1 << j] * aa[i][j] % MOD;
		for (b = 1; b < 1 << n; b++)
			dp[b] = dp[b & b - 1] * dp[b & -b] % MOD;
		for (b = 0; b < 1 << n; b++)
			dq[b] = dq[b] * (1 - dp[b]) % MOD;
	}
	for (b = 1; b < 1 << n; b++)
		dr[b] = dr[b & b - 1] * dr[b & -b] % MOD;
	ans = 0;
	for (b = 0; b < 1 << n; b++)
		ans = (ans + dr[b] * dq[(1 << n) - 1 ^ b]) % MOD;
	return sub(1,ans);
}

int rrr ;
int rr[mn][mn];

bool    check()
{
    FOR(i,1,n)
    {
        int ck = 1;
        FOR(j,1,n) ck=ck*rr[i][j];
        if (ck) return 1;
    }
    FOR(j,1,n)
    {
        int ck = 1;
        FOR(i,1,n) ck = ck*rr[i][j];
        if (ck) return 1;
    }
    return 0;
}

void    att(int i, int j, int pr)
{
    if (i>n)
    {
        if (check()) rrr = add(rrr, pr);
        return;
    }
    int ii, jj;
    if (j<n) {ii=i; jj=j+1;} else {ii=i+1; jj=1;}
    rr[i][j] = 1;
    att(ii,jj,mul(pr,t[i][j]));
    rr[i][j] = 0;
    att(ii,jj,mul(pr,sub(1,t[i][j])));
}

int    bruteforce()
{
    rrr = 0;
    att(1,1,1);
    return rrr;
}

void    reset()
{
    //reset
    FOR(i,1,n)
    FOR(j,1,n) t[i][j]= a[i][j];
    //
}

void    solve()
{
    // hang va cot
    reset();
    int res = process();
    int yes;
    int tg;
    int tg2;
    int mid;
   // cout << res << ' ' << tg2 << '\n';
    // cheo chinh
    reset();
    yes = 1;
    FOR(i,1,n) yes = mul(yes, a[i][i]), t[i][i] = 1;
    tg = process();
    //cout << tg << ' ' << tg2 << '\n';
    mid = mul(yes,tg);

    res = add(res,yes);
    res = sub(res,mid);

    // cheo phu
    reset();
    yes = 1;
    FOR(i,1,n) yes = mul(yes, a[i][n-i+1]), t[i][n-i+1] = 1;
    tg = process();
    //cout << tg << ' ' << tg2 << '\n';
    mid = mul(yes,tg);

    res = add(res,yes);
    res = sub(res,mid);

    // cc va cp (tru ra)
    reset();
    yes = 1;
    FOR(i,1,n) yes = mul(yes, a[i][i]), t[i][i] = 1;
    FOR(i,1,n) if (i!=n-i+1)
    {
        yes = mul(yes, a[i][n-i+1]);
        t[i][n-i+1] = 1;
    }
    tg = process();
   //cout << tg << ' ' << tg2 << '\n';
    mid = mul(yes,tg);

    res = sub(res,yes);
    res = add(res,mid);

    cout << res;
}

int main()
{
    cin >> n;
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            cin>>a[i][j];
            a[i][j] = mul(a[i][j], INV_MAU);
        }
    }
    solve();
}
