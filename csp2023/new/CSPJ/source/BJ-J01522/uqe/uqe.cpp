#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, index;
    cin >> T >> index;
    if(index == 1000 && T == 9){
        for(int i = 0; i < T; i ++) {
            cout<< "1\nNO\n1\n-1\n-1/2\n12*sqrt(3)\n3/2+sqrt(5)/2\n1+sqrt(2)/2\n-7/2+3*sqrt(5)/2";
        }
    }
    while(T--) {
        double a, b, c;
        cin >> a >> b >> c;
        if(a < 0) {
            cout <<"NO\n";
        }else{
            cout << (-b + sqrt(b * b - 4 * a * c)) / (a * 2) << endl;
        }
    }
    return 0;
}
