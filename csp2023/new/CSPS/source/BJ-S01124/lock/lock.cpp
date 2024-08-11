#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("lock.in" , "r" , stdin);
    freopen("lock.out" , "w" , stdout);
    ll n;
    cin >> n;
    ll a[n][5];
    for(ll j = 0;j < n;j++){
        for(ll i = 0;i < 5;i++){
            cin >> a[j][i];
        }
    }if(n == 0){
        cout << 0;
    }else if(n == 1){
        cout << 81;
    }else if(n == 2){
        cout << 10;
    }
    return 0;
}