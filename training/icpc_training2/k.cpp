#include <bits/stdc++.h>
#define F(i,a,b) for (int i = a; i <=b; i++)
using namespace std;

const int maxn = 1010;

int main()
{
    //freopen("a.txt", "r", stdin);

    string s, t;
    int cs[maxn], ct[maxn];
    F(i,0,maxn-2) cs[i] = ct[i] = 0;

    getline(cin, s);
    for (int i = 0; i < s.length(); i++) cs[s[i]]++;
    getline(cin, t);
    for (int i = 0; i < t.length(); i++) ct[t[i]]++;

    for (char i = 'a'; i <= 'z'; i++)
        if (ct[i] > cs[i]) cout << i;
    if (ct[' '] > cs[' ']) cout << ' ';

    return 0;
}
