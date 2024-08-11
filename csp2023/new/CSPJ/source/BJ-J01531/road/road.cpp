#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long n, d;
    cin>>n>>d;
    long long v[n], a[n + 1];
    long long money = 0, ke = 0;
    for(int i = 1; i <= n - 1; i++){
        cin>>v[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    long long o = 1;
    for(int i = 1; i <= n - 2; i++){
        if(a[o] <= a[i + 1]){
            v[o] += v[i + 1];
            v[i + 1] = 0;
        }else{
            o = i + 1;
        }
    }
    for(int i = 1; i <= n - 1; i++){
        if(v[i] != 0){
            if((v[i] - ke) % d == 0){
                money += (v[i] - ke) / d * a[i];
            }else{
                money += ((v[i] - ke) / d + 1) * a[i];
                ke = ke + ((v[i] - ke) / d + 1) * d - v[i];
            }
        }
    }
    cout<<money;
    return 0;
}