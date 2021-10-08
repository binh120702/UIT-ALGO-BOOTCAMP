#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

string S, a[20004];
int n, qq, nex[505][30], treeCount[20004*4], res[300005];
vector<int> addString[505];

struct Query{
    int l, r, k, id;
} q[300005];

bool    cmp(Query a, Query b){
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

void    addTree(int id, int l, int r, int u)
{
    if (l>u) return;
    if (r<u) return;
    if (l==r)
    {
        treeCount[id] = 1;
        return;
    }
    int m = (l+r)/2;
    addTree(id*2  , l  , m, u);
    addTree(id*2+1, m+1, r, u);
    treeCount[id] = treeCount[id*2] + treeCount[id*2+1];
}

void    resetTree(int id, int l, int r)
{
    treeCount[id] = 0;
    if (l==r) return;
    int m = (l+r)/2;
    resetTree(id*2  , l  , m);
    resetTree(id*2+1, m+1, r);
}

int     getPosK(int i, int l, int r, int k)
{
    if (l == r) return l;
    int cLeft = treeCount[i*2];
    int m = (l+r)/2;
    if (cLeft >= k)
        return getPosK(i*2,l,m,k);
    else
        return getPosK(i*2+1,m+1,r,k-cLeft);
}

void    push(int pos)
{
    for(int stringIndex : addString[pos])
        addTree(1,1,n, stringIndex);
}

void    solve()
{
    // sort n strings and qq querys
    sort(a+1, a+1+n);
    sort(q+1, q+1+qq, cmp);

    int m = S.length();
    S = '@' + S;
    // init next_char of S
    FORD(i,m,1)
    {
        for(char c = 'a'; c <= 'z'; c++)
            nex[i][c-'a'] = nex[i+1][c-'a'];
        nex[i][S[i]-'a'] = i;
    }

    // solve
    int curQ = 1;
    FOR(L,1,m) if (L == q[curQ].l)
    {
        resetTree(1,1,n);
        FOR(i,1,m) addString[i].clear();
        FOR(i,1,n)
        {
            int pos = L;
            int getAll = 1;
            FOR(j,0,(int)a[i].length()-1)
            {
                if (pos == m+1 || nex[pos][a[i][j]-'a']==0)
                {
                    getAll = 0;
                    break;
                }
                pos = nex[pos][a[i][j]-'a'] + 1;
            }
            if (getAll) addString[pos-1].push_back(i);
        }
        int R = L;
        while (L==q[curQ].l)
        {
            while (R <= q[curQ].r)
            {
                push(R);
                R++;
            }
            while (L==q[curQ].l && R-1==q[curQ].r)
            {
                if (treeCount[1] < q[curQ].k) res[q[curQ].id] = 0; else
                res[q[curQ].id] = getPosK(1,1,n,q[curQ].k);
                curQ++;
            }
        }
    }
    FOR(i,1,n) a[i] = a[i].substr(0,10);
    a[0] = "NO SUCH WORD";
    FOR(i,1,qq) cout << a[res[i]] << '\n';
}

int     main()
{
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
    cin >> S;
    cin >> n >> qq;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,qq)
    {
        cin >> q[i].l >> q[i].r >> q[i].k;
        q[i].id = i;
    }

    solve();
    return 0;
}

