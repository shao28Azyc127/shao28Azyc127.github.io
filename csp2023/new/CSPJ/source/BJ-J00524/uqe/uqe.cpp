#include<bits/stdc++.h>
using namespace std;
int T, M;
void Solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int d = b * b - 4 * a * c;
    if(d < 0){
        cout << "NO" << endl;
        return;
    }
    int x1 = (-b-sqrt(d)) / (2*a);
    int x2 = (-b+sqrt(d)) / (2*a);
    int x = max(x1, x2);
    cout << x << endl;
    return;
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    while(T--){
        Solve();
    }
    return 0;
}
