#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n, d, minprice = maxn, oilk, ans;
int km[maxn];
int price[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 0;i<n-1;i++) cin >>km[i];
    for(int i = 0;i<n;i++){
        cin >> price[i];
    }
    for(int i = 0;i<n-1;i++){
        minprice = min(minprice, price[i]);
        int minoil=(km[i]-oilk+d-1)/d;
        ans+=minoil*minprice;
        oilk+=minoil*d;
        oilk-=km[i];
    }
    cout <<ans<<endl;
    return 0;
}
