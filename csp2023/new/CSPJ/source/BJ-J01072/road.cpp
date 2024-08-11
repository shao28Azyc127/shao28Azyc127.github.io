#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5+5;

long long n, d, v[N], a[N], mn = INT_MAX, cnt, meter;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 0; i < n-1 ; i++) {
        cin >> v[i];
    }
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++) {
        mn = min(mn, a[i]);
    }
    if(mn == a[0]){
        for(int i = 0 ; i < n-1 ; i++) {
            meter+=v[i];
        }
        if(meter%d == 0) cnt = meter/d*mn;
        else if(meter%d != 0) cnt = (meter/d + 1)*mn;
    }
    cout << cnt;
    return 0;
}
