#include<bits/stdc++.h>
using namespace std;
int n, d, v[100005], a[100005], cost, last = 1, s;
void add(int i){
    v[i] -= s;
    s = 0;
    if(d >= v[i]) cost += a[last];
    else{
        if(v[i] % d){
            cost += (v[i] / d + 1) * a[last];
            s = (v[i] / d + 1) * d- v[i];
        }
        else cost += (v[i] / d) * a[last];

    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i < n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++){
        add(i - 1);
        if(a[last] > a[i]) last = i;
    }
    cout << cost;
    return 0;
}
