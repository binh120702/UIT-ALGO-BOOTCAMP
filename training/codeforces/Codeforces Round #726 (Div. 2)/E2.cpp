// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

int     n, k;
string  s;
const int md[2] = {1000000000+7, 1000000000+1};
const int bas[2] = {100, 50};
const int mn = 5e5+ 5;
long long h[mn][2], pw[mn][2];

long long   get_hash(int l, int r, int k)
{
    return (h[r][k]-h[l-1][k]*pw[r-l+1][k]+1LL*md[k]*md[k])%md[k];
}

int     smaller(int pos, int cur)
{
    // 1 -> n-pos+1
    // [pos, cur-1]+ [1, n-cur+1]
    int l = 1, r = n-pos+1, mid, res=0;
    while (l<=r)
    {
        mid = (l+r)/2;
        long long ha[2] , hb[2];
        ha[0] = get_hash(1,mid,0);
        ha[1] = get_hash(1,mid,1);
        if (mid<=cur-pos)
        {
            hb[0] = get_hash(pos, pos+mid-1, 0);
            hb[1] = get_hash(pos, pos+mid-1, 1);
        } else
        {
            hb[0] = get_hash(pos, cur-1, 0) * pw[mid-(cur-pos)][0]
            + get_hash(1, mid-(cur-pos),0);
            hb[0] = hb[0] % md[0];

            hb[1] = get_hash(pos, cur-1, 1) * pw[mid-(cur-pos)][1]
            + get_hash(1, mid-(cur-pos), 1);
            hb[1] = hb[1] % md[1];
        }
        if (ha[0]==hb[0] && ha[1] == hb[1]){
            res = mid;
            l = mid+1;
        }else r=mid-1;
    }
    if (res<n-pos+1)
    {
        char ca = s[res+1];
        char cb;
        if (res<=cur-pos) {
            cb = s[pos+res];
        } else cb = s[res-(cur-pos)+1];
        return ca<cb;
    } else return 0;
}

void    make_hash()
{
    pw[0][0]=pw[0][1]= 1;
    FOR(k,0,1)
    FOR(i,1,n)
    {
        h[i][k] = (h[i-1][k]*bas[k] + s[i]-'a'+1)%md[k];
        pw[i][k]= (pw[i-1][k]*bas[k])%md[k];
    }
}

void	solve()
{
    int minPos = 1;
    string tmp = s;
    int cur = n+1;
    make_hash();
    FORD(i,n,2)
    {
        if (smaller(i,cur)){
            cur = i;
        }
    }
    FOR(i,1,k/(cur-1))
    {
        FOR(j,1,cur-1) cout << s[j];
    }
    FOR(j,1,k%(cur-1)) cout << s[j];
}

int 	main()
{
    cin>>n>>k;
    cin>>s;
    s='$'+s;
    solve();

	return 0;
}
