#include <bits/stdc++.h>
using namespace std;

int a[100001], b[100001];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, minn, sum = 0;
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        cin >> a[100001];
        sum += a[i];
    }
    for(int i = 1; i < n; i++){
        cin >> b[i];
        minn = min(minn, b[i]);
    }
    if(minn == b[1]){
        if(sum % m == 0){
            cout << sum / m * b[1];
        }else{
            cout << (sum / m + 1) * b[1];
        }
    }else{
        cout << a[1] / m * b[1] + minn * (sum / m);
    }
    return 0;
}