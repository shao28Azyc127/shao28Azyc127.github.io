#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;



int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    int t;
    double m;
    cin >> t >> m;
    while (t--){
        double a, b, c;
        double d = pow(b, 2) - 4 * a * c;
        if (d < 0){
            cout << "No" << endl;
            continue;
        }
        double ans = 0.0;
        double ans_1 = (sqrt(d) - b) / a * 2;
        double ans_2 = (-sqrt(d) - b) / a * 2;
        if (ans_1 > ans_2) ans = ans_1;
        else ans = ans_2;
        cout << ans;
    }
    return 0;
}
