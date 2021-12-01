#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int mn = 1e6 + 5;
int n, d[mn];
bool dp[mn];

void runTest(int ts){
    ofstream fo (("output" + to_string(ts) + ".txt").c_str());

    int s = 0;
    sort(d+1,d+1+n);

    s = 0;
    dp[0] = true;
    FOR(i,1,n){
        FORD(j,s,0)
            if (dp[j]) dp[j+d[i]] = true;
        s+= d[i];
    }

    int cnt = 0;
    long long res = 0;
    FORD(i,s,0)
        if (dp[i]){
            cnt++;
            res+= s-i+1;
        } else res+= cnt;
    fo << res;

    FOR(i,0,s) dp[i] = false;
    fo.close();
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int Rand(int l, int h) {
    assert(l <= h);
    return l + (rd() % (h - l + 1));
}

const int LEFT_TEST = 9;
const int RIGHT_TEST = 9;

void genTest(int ts){
    ofstream fo (("input" + to_string(ts) + ".txt").c_str());
    int n = Rand(100,100);
    fo << n << '\n';
    FOR(i,1,n) fo << 10000 << '\n';
    fo.close();
}


int     main(){
    for(int i=LEFT_TEST; i<= RIGHT_TEST; i++){
        genTest(i);

        //
        ifstream fi  (("input" + to_string(i) + ".txt").c_str());
        fi >> n ;
        FOR(i,1,n) fi >> d[i];
        runTest(i);
    }
}

