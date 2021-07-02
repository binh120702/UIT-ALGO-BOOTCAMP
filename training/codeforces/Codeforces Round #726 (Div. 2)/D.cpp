// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

int     n;
int     f[10000];
void    init(){
    FOR(i,1,1000){
        FOR(j,2,i-1)if (i%j==0){
            if (f[i-j]==0)
            {
                f[i] = 1;
                break;
            }
        }
        if (i%2==0){
        cout << i ;
        if (f[i]) cout << " win\n"; else cout << " lose\n";}
    }
}

void	solve()
{
    long long ft = 2;
    while (ft<=n){
        if (ft==n) {
                cout << "Bob\n" ; return;}
        ft*=4;
    }
    if (n%2==0 ) {
        cout << "Alice\n";
    } else cout << "Bob\n";
}

int 	main()
{
	//init();
    int ts;
    cin>>ts;
    while (ts--){
        cin>>n;
        solve();
	}
	return 0;
}
