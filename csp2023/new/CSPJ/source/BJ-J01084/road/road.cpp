#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int v[maxn],a[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    for (int i = 1;i < n;i++){
        cin >> v[i];
    }
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ans = 0,minn = 2e9,pre = 0;
    for (int i = 1;i < n;i++){
        if (v[i] <= pre){
            pre -= v[i];
            continue;
        }
        v[i] -= pre;
        minn = min(minn,a[i]);
        if (v[i] % d == 0){
            int t = v[i] / d;
            pre = 0;
            ans += t * minn;
        }
        else{
            int t = v[i] / d + 1;
            pre = t * d - v[i];
            ans += t * minn;
        }
    }
    cout << ans << endl;
    return 0;
}



