#include <bits/stdc++.h>
using namespace std;
long long n,d,v[100005],a[100005],minn,tmp,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 2;i <= n;i++) cin >> v[i];
    for(int i = 1;i <= n;i++) cin >> a[i];
    minn = a[1];
    for(int i = 2;i <= n;i++){
        if(tmp > v[i]){
            tmp -= v[i];
            v[i] = 0;
        }else{
            v[i] -= tmp;
            tmp = 0;
        }
        ans += (v[i] + d - 1) / d * minn;
        tmp += (v[i] + d - 1) / d * d - v[i];
        minn = min(minn,a[i]);
    }
    cout << ans;
    return 0;
}
