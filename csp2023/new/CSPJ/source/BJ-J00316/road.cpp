#include <iostream>
#include <cmath>
using namespace std;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, dis = 0, d, a[100005], v[100005], ans = 0, qzhv[100005]={};
    cin >> n >> d;
    for(int i = 1; i <= n-1; i++){
        cin >> v[i];
        qzhv[i] = qzhv[i-1]+v[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int now = a[1];
    for(int i = 1; i < n; i++){
        if(now > a[i]){
            now = a[i];
        }
        int x = (qzhv[i]-dis)/d+bool((qzhv[i]-dis)%d);
        dis += x*d;
        ans += x*now;
    }
    cout << ans;
}
