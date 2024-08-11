#include<iostream>
#include<sys/stat.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
   // freopen("road.in", "r", stdin);
   // freopen("road.out", "w", stdout);
    int n, d, a[100000], v[100000], ans = 0;
    cin >> n >> d;
    for(int i = 0; i < n - 1; i++){
        cin >> v[i];
        ans += v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << ((ans += (ans % d)) / d) * a[0];
    return 0;
}
