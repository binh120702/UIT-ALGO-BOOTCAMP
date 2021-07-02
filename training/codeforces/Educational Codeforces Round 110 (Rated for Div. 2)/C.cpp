// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

string s;

void	solve()
{
    int n = s.length();
    long long res = 0;
    int pos[2][2];
    pos[1][0] = pos[1][1] = pos[0][0] = pos[0][1] = n;
    FORD(i,n-1,0)
    {
        int typ = i%2;
        if (s[i]=='0')
        {
            int nex = min(pos[1][typ], pos[0][1-typ]);
            res += nex-i;
            pos[0][typ] = i;
        } else
        if (s[i]=='1')
        {
            int nex = min(pos[0][typ], pos[1][1-typ]);
            res += nex-i;
            pos[1][typ] = i;
        } else
        {
            int nex1 = min(pos[1][typ], pos[0][1-typ]);
            int nex2 = min(pos[0][typ], pos[1][1-typ]);
            int nex3 = max(nex1, nex2);
            res += nex3-i;
        }
    }
    cout << res << '\n';
}

int 	main()
{
    int ts;
    cin>>ts;
    while (ts--){
        cin>>s;
        solve();
    }

	return 0;
}
