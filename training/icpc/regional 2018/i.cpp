#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
struct Vertex{
    // prefix that exist
    int next[2];
    int link = 0;
    // assume: what happens when we go[i]
    int go[2];
    bool leaf = false;
    string prefix = "";
    Vertex() {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

const int mn = 100;
int n, m;
string p;
long long dp[51][983040][2];

vector<int> pos;
vector<string> state;
vector<Vertex> tree(1);

void att(int i, string & s)
{
    if (i>=(int)pos.size())
    {
        state.push_back(s);
        return;
    }
    s[pos[i]] = '0';
    att(i+1, s);
    s[pos[i]] = '1';
    att(i+1, s);
}

void generateAllState(){
    m = p.length();
    FOR(i,0,m-1) if (p[i] == '*')
        pos.push_back(i);
    string pp = p;
    att(0, pp);
}

int treeFind(string s)
{
    int cur = 0;
    for(char ch: s )
    {
        if (tree[cur].next[ch-'0'] == -1) return 0;
        cur = tree[cur].next[ch-'0'];
    }
    return cur;
}

void generateAutomaton(){
    // create trie
    for(string s : state)
    {
        int cur = 0;
        for(char ch : s)
        {
            int c = ch-'0';
            if (tree[cur].next[c] == -1)
            {
                tree[cur].next[c] = tree.size();
                tree.emplace_back();
            }
            tree[tree[cur].next[c]].prefix = tree[cur].prefix+ch;
            cur = tree[cur].next[c];
        }
    }
    // cout << tree.size() << '\n';

    // create automaton
    FOR(c,0,1) if (tree[0].next[c] == -1)
    tree[0].go[c] = 0; else tree[0].go[c] = tree[0].next[c];

    for(string s : state)
    {
        int cur = 0;
        for(char ch : s)
        {
            cur = tree[cur].next[ch-'0'];
            FOR(c,0,1)
            {
                string tmp = tree[cur].prefix;
                if (c==0) tmp = tmp + "0"; else tmp = tmp + "1";
                tree[cur].go[c] = 0;
                //cout << tmp << ' ' ;
                while (tmp.length())
                {
                    int pos = treeFind(tmp);
                    if (pos)
                    {
                        tree[cur].go[c] = pos;
                        break;
                    } else tmp.erase(0,1);
                }
                // cout << tree[tree[cur].go[c]].prefix << '\n';
            }
            tree[cur].leaf = (tree[cur].prefix.length() == p.length());
        }
    }
}

void solve(){
    // init next state array
    generateAllState();

    // init automaton tree
    generateAutomaton();

    // dp
    int m = tree.size();
    dp[0][0][0] = 1;

    FOR(i,0,n-1)
    FOR(j,0,m-1)
    FOR(exist,0,1)
    FOR(c,0,1)
    {
        int new_exist = exist;
        int nex = tree[j].go[c];
        if (tree[nex].leaf)
            new_exist = 1;
        dp[i+1][nex][new_exist] += dp[i][j][exist];
    }
    long long res = 0;
    FOR(j,0,m-1) res += dp[n][j][1];
    cout << res;
}

int main()
{
    cin >> n;
    cin >> p;
    solve();
}
