#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll minn = 10000005 , n , v[1000005] , a[1000005];
ll ans , sum[1000006] , cnt;
double m;

void PraseIn(){
    cin >> n >> m;
    for(ll i = 1; i < n; i++){
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void Core(){
    for(ll i = 1; i < n; i++){
        if(sum[i] <= cnt){
            continue;
        }
        minn = min(minn , a[i]);
        ll cc = max(ceil((sum[i] - cnt)*1.0 / m) , 0.0);
        cnt += cc * (ll)m;
        ans += cc * minn;
    }
}
void WriteOut(){
    cout << ans;
}
int main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    PraseIn();
    Core();
    WriteOut();
    return 0;
}
