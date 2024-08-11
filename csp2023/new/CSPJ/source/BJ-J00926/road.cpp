#include<bits/stdc++.h>
using namespace std;

int n,d;
long long v[100005];
long long a[100005];
long long mi,ans,di;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> d;
    for(int i = 1;i < n;i++){
        cin >> v[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    mi = a[1];
    a[n] = -1;
    for(int i = 1;i <= n;i++){
        if(mi > a[i]){
            if(di > 0){
                ans += (di+d-1)/d*mi;
                di -= (di+d-1)/d*d;
            }
            mi = a[i];
        }
        di += v[i];
    }
    cout << ans;
}
