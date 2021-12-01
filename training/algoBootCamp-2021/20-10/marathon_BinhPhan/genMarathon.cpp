#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int mn = 2e3 + 5;
char s[mn][5];
int n;

void runTest(int ts){
    ofstream fooo(("output" + to_string(ts) + ".txt").c_str());
    int seconds = 0;
    FOR(i,1,n) {
        seconds += ((s[i][0]-'0')*10+s[i][1]-'0')*60;
        seconds += (s[i][3]-'0')*10+s[i][4]-'0';
    }
    int mm = seconds / 60;
    seconds %= 60;
    int hh = mm / 60;
    mm %= 60;
    if (hh<10) fooo<<'0';
    fooo << hh << ':' ;
    if (mm<10) fooo<<'0';
    fooo << mm << ':' ;
    if (seconds<10) fooo<<'0';
    fooo << seconds;
    fooo.close();
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int Rand(int l, int h) {
    assert(l <= h);
    return l + (rd() % (h - l + 1));
}

const int LEFT_TEST = 10;
const int RIGHT_TEST = 10;

void genTest(int ts){
    const int MX = 86399;
    ofstream fo (("input" + to_string(ts) + ".txt").c_str());
    // n = 1000
    fo << "1000\n";
    FOR(i,1,1000){
        int x = 86;
        if (x/60<10) fo << '0';
        if (x%60<10)
            fo << x/60 << ":0" << x%60 << '\n';
        else
            fo << x/60 << ":" << x%60 << '\n';

    }fo.close(); return;
    //fo << "1000\n";
    //FOR(i,1,1000) fo << "00:00\n"; fo.close(); return;
    int n = 0;
    int cur = MX;
    int lim = 190;
    int a[mn];

    while (cur > 0){
        n++;
        if (cur <= lim)
            a[n] = cur;
        else
            a[n] = Rand(0,lim);
        cur -= a[n];
    }
    fo << n << '\n';
    FOR(i,1,n){
        int x = a[i];
        if (x/60<10) fo << '0';
        if (x%60<10)
            fo << x/60 << ":0" << x%60 << '\n';
        else
            fo << x/60 << ":" << x%60 << '\n';
    }
    fo.close();
}


int     main(){
    for(int i=LEFT_TEST; i<= RIGHT_TEST; i++){
        genTest(i);

        //
        ifstream fi  (("input" + to_string(i) + ".txt").c_str());
        fi >> n ;
        FOR(i,1,n) fi >> s[i];
        runTest(i);
    }
}

