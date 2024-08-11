#include <bits/stdc++.h>
using namespace std;

int t, m, a, b, c;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    cin >> t >> m;
    for (int i = 1; i <= t; i++){
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0){
            cout << "NO" << endl;
            continue;
        }
        if (pow(sqrt(b * b - 4 * a * c), 2) == (double)(b * b - 4 * a * c)){
            double x1 = -b + sqrt(b * b - 4 * a * c); int x2 = 2 * a;
            if (x1 - (int)x1 == 0){
                if (abs(x2 / gcd((int)x1, x2)) == 1 || x1 == 0){
                    cout << (int)x1 / gcd((int)x1, x2) << endl;
                    continue;
                }
                if ((int)x1 / gcd((int)x1, x2) < 0 && (int)x2 / gcd((int)x1, x2) < 0){
                    cout << abs((int)x1 / gcd((int)x1, x2)) << "/" << abs((int)x2 / gcd((int)x1, x2)) << endl;
                    continue;
                }
                if ((int)x1 / gcd((int)x1, x2) < 0 || (int)x2 / gcd((int)x1, x2) < 0){
                    cout << "-" << abs((int)x1 / gcd((int)x1, x2)) << "/" << abs((int)x2 / gcd((int)x1, x2)) << endl;
                    continue;
                }
                cout << "-" << abs((int)x1 / gcd((int)x1, x2)) << "/" << abs((int)x2 / gcd((int)x1, x2)) << endl;
                continue;
            }
            cout << endl;
        }

    }

    return 0;
}
