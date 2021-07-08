#include <bits/stdc++.h>

#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
#define double long double
double c, m, p, v, res;
double EPS = 1e-9;
bool eq(double a, double b){
    return abs(a-b) < EPS;
}
void    att(double c, double m, double p, double prob, double mul)
{
    // c
    if (c>-1)
    {
        if (m>-1)
        {
            if (c<=v || eq(c,v))
            att(-2, m+c/2.0, p+c/2.0, prob*c, mul+1); else
            att(c-v, m+v/2.0, p+v/2.0, prob*c, mul+1);
        } else
        {
            if (c<=v || eq(c,v))
            att(-2, m, p+c, prob*c, mul+1); else
            att(c-v, m, p+v, prob*c, mul+1);
        }
    }
    // m
    if (m>-1)
    {
        if (c>-1)
        {
            if (m<=v || eq(m,v))
            att(c+m/2.0, -2, p+m/2.0, prob*m, mul+1); else
            att(c+v/2.0, m-v, p+v/2.0, prob*m, mul+1);
        } else
        {
            if (m<=v || eq(m,v))
            att(c, -2, p+m, prob*m, mul+1); else
            att(c, m-v, p+v, prob*m, mul+1);
        }
    }
    // p
    double temp = prob*p*mul;
   // temp = 1.0*int(temp*1000000000)/1000000000;
    res+= temp;
}

void    solve()
{
    res = 0;
    att(c,m,p,1,1);
    cout << fixed << setprecision(10) << res << '\n';
}

int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        cin >> c >> m >> p >> v;
        solve();
    }

}
