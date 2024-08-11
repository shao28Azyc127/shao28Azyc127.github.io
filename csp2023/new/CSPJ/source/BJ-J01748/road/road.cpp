#include <bits/stdc++.h>
using namespace std;
int n, d, sum, ans;
int v[100005], a[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i <= n-1;i++){
        cin >> v[i];
        sum += v[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int t = sum / d;
    if(t % d >= 1){
        t++;
    }
    ans = t*a[1];
    cout << ans;
    return 0;
}
