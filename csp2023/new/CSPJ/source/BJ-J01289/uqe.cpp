#include <bits/stdc++.h>
using namespace std;
int a, b, c, t, m;
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for(int i = 1; i <= t; i++){
        cin >> a >> b >> c;
        if(b == 0){
            if(c == 0){
                cout << "0"<< endl;
            } else if(c > 0){
                cout <<"NO" << endl;
            }
        } else if(b * b - 4 * a * c < 0){
            cout <<"NO"<< endl;
        } else {
            int x = (sqrt(b * b - 4 * a * c) - b) / (2 * a);
            cout << x << endl;
        }
    }
    return 0;
}
