#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
string s;
int n;
const int mn = 100005;
const int md = 998244353;
int     list_pr[mn], added[mn], cntPr, add_list_pr[mn], pr[mn];

void    fact(int i, int ad)
{
    while (i>1)
    {
        int prime_ = pr[i];
        if (!added[prime_])
        {
            list_pr[++cntPr] = prime_;
            added[prime_] = cntPr;
        }
        add_list_pr[added[prime_]]+=ad;
        i/=prime_;
    }
}

long long power(int x, int y)
{
    if (y==0) return 1;
    long long t = power(x, y/2);
    t = (t*t) %md;
    if (y%2==0) return t; else return (t*x)%md;
}

long long cntCKN(int k, int n)
{
    FOR(i,k+1,n) fact(i, 1);
    FOR(i,2,n-k) fact(i,-1);
    long long res = 1;
    FOR(i,1,cntPr)
        res=(res*power(list_pr[i],add_list_pr[i]))%md;;
    FOR(i,1,cntPr)
    {
        added[list_pr[i]] = 0;
        add_list_pr[i] = 0;
    }
    cntPr=0;
    return res;
}

void    solve()
{
    long long res = 1;
    int cnt0 = 0;
    int cnt1 = 0;
    for(int i=1; i<=n;)
    {
        if(s[i]=='0')
        {
            cnt0++;
            i++;
        } else
        {
            int tmp = 0;
            while (i<=n && s[i]=='1')
            {
                tmp++;
                i++;
            }
            cnt1+= tmp/2;
        }
    }
    res = cntCKN(cnt1, cnt1+cnt0);
    cout << res << '\n';
}

void    primeI()
{
    pr[1] = 1;
    for(int i = 2; i<=100000; i++) if (pr[i]==0)
    {
        pr[i] = i;
        long long j = 1LL*i*i;
        while (j<=100000)
        {
            pr[j] = i;
            j+=i;
        }
    }
}

int main()
{
    primeI();
    int ts;
    cin >> ts;
    while (ts--)
    {
        cin >> n >> s;
        s='@'+s;
        solve();
    }
}
