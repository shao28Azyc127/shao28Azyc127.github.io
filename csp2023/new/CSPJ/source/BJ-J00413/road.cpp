#include<iostream>
using namespace std;
int n, d;
int v[100010] = {0};
int a[100010] = {0};
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    long long ans = 0;
    for(int i = 1; i < n; i++){
        cin >> v[i];
        ans += v[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ans /= d;
    ans *= a[1];
    cout << ans << endl;
    return 0;
}