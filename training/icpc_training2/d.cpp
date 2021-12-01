/*nhat-huy*/
#include <bits/stdc++.h>
using namespace std;

const int maxCoor = 1e6;
const int64_t oo = 1e15;
int n;
bool stop;

int64_t calc(int x, int y){
    cout << x << ' ' << y << '\n' << flush;
    int64_t temp; cin >> temp;
    if (temp == 0) stop = true;
    return temp;
}

void solve(){
    stop = false;
    int left = 0, right = maxCoor;
    while (right - left >= 3){
        int mid1 = left + (right - left) / 3, mid2 = left + 2 * ((right - left) / 3);
        int64_t dist1 = calc(mid1, 0);
        if (stop) return;
        int64_t dist2 = calc(mid2, 0);
        if (stop) return;
        if (dist1 <= dist2) right = mid2; else left = mid1;
    }

    int64_t minDist = oo, ans = -1;
    for(int mid = left; mid <= right; ++ mid){
        int64_t dist = calc(mid, 0);
        if (stop) return;
        if (dist < minDist){
            minDist = dist;
            ans = mid;
        }
    }
    calc(ans, sqrt(minDist));
}

int main()
{
    cin >> n;
    while (n--) solve();
    return 0;
}
