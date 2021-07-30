#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
string s;
const int mn = 505;
const int md = 998244353;
int n, a[mn*2][mn], id[mn*2], removed[mn*2];

void    solve()
{
    long long way = 1;
    vector<int> res;
    int cur_size = n*2;
    FOR(i,1,cur_size) removed[i]=0;
    while (int(res.size()) < n)
    {
        int find_gud = 0;
        FOR(j,1,n)
        {
            int cnt[mn];
            int pos[mn];
            FOR(i,1,n)
            {
                cnt[i] = 0;
                pos[i] = 0;
            }
            FOR(i,1,cur_size) if (!removed[i])
            {
                cnt[a[i][j]]++;
                pos[a[i][j]] = i;
            }
            FOR(i,1,n) if (cnt[i]==1)
            {
                find_gud = pos[i];
                break;
            }
            if (find_gud) break;
        }
        if (find_gud)
        {
            int i = find_gud;
            res.push_back(id[i]);
            find_gud = 1;
            int temp_[505];
            FOR(j,1,n) temp_[j] = a[i][j];
            FORD(i2,cur_size,1) if (!removed[i2])
            {
                int bad = 0;
                FOR(j,1,n) if (a[i2][j]==temp_[j])
                {
                    bad = 1;
                    break;
                }
                if (bad) removed[i2]=1;
            }
        }
        if (!find_gud)
        {
            way = way*2 % md;
            int iii;
            FOR(ii,1,cur_size) if (!removed[ii])
            {
                iii=ii;
                break;
            }
            res.push_back(id[iii]);
            int temp_[505];
            FOR(j,1,n) temp_[j] = a[iii][j];
            FORD(i2,cur_size,1)
            {
                int bad = 0;
                FOR(j,1,n) if (a[i2][j]==temp_[j])
                {
                    bad = 1;
                    break;
                }
                if (bad) removed[i2]=1;
            }
        }
    }
    cout << way << '\n';
    for(int v : res) cout << v << ' '; cout << '\n';
}

int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        cin >> n;
        FOR(i,1,2*n)
        {
            FOR(j,1,n) cin>>a[i][j];
            id[i]=i;
        }
        solve();
    }
}
