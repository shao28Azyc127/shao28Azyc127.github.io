#include<bits/stdc++.h>
using namespace std;
int n, d;
long long v[100005];
int a[100005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 2; i <= n; i++){
        cin >> v[i];
        v[i] = v[i] + v[i - 1];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int t = 1;
    int w = 1;
    long long m = 0;
    long long ans = 0;
    while(w < n){
        if(a[w] <= a[t]){
            t = w;
        }
        ++w;
        long long x = v[w] - m;
        long long y = x / d;
        bool z = x % d;
        y += z;
        m += y * d;
        ans += y * a[t];
    }
    cout << ans;
return 0;
}