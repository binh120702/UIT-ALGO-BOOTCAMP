#include<bits/stdc++.h>
using namespace std;

long double D, a1, a2, vmax, t, ans;

int main()
{
    cin >> D >> a1 >> a2 >> vmax >> t;

    long double a= (a1+a2)/(2*a1*a2);
    long double delta = t*t+ 4*D*a;
    long double v = (-t+sqrt(delta))/(2*a);

    if (v<=vmax)
        ans= v/a1 + v/a2 + t;
    else
        ans = D/vmax + vmax/(2*a1) + vmax/(2*a2);

    ans+=5e-14;

    cout << setprecision(12) << fixed << ans;
}