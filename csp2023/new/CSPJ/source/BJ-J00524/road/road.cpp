#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
long long n, d, v[N], a[N], Min[N], cnt = 0, km = 0, oil;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(long long i = 1; i <= n - 1; i++){
        cin >> v[i];
    }

    Min[0] = INT_MAX;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
        Min[i] = min(Min[i-1], a[i]);
    }

    oil = v[1] / d;
    if(v[1] % d != 0) oil++;
    cnt += oil * a[1];
    km += oil * d;

    for(long long i = 2; i <= n; i++){
        if(i == n) break;
        km -= v[i-1];
        long long vst = v[i] - km;
        oil = vst / d;
        if(vst % d != 0) oil++;
        cnt += oil * Min[i];
        km += oil * d;
    }

    cout << cnt << endl;
    return 0;
}
