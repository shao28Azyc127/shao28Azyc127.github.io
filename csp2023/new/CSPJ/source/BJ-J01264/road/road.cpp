#include <bits/stdc++.h>
using namespace std;
int a[100005];
int v[100005];
int sum = 0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    for(int i = 1;i < n;i++){
        cin >> v[i];
        sum += v[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cout << a[1] * (sum / d + (sum % d != 0)) << endl;
    return 0;
}