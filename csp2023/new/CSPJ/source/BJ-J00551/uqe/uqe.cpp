#include <bits/stdc++.h>

using namespace std;

int T, M;

void help(int a, int b){
    int c = __gcd(a, b);
    a /= c;
    b /= c;
    if (b == 1) cout << a;
    else if (b == -1) cout << -a;
    else if (b < 0) cout << -a << "/" << -b;
    else cout << a << "/" << b;
}

int help2(int x){
    for (int i = 1; i * i <= x; i++)
        if (i * i == x) return i;
    return -1;
}

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;

    while (T--){
        int a, b, c;
        cin >> a >> b >> c;
        int t = b*b - 4*a*c;
        if (t < 0)
            cout << "NO" << endl;
        else if (t == 0){
            help(-b, 2*a);
            cout << endl;
        }
        else{

            int x = help2(t);
            if (x != -1){
                if ((-b + x)* 1.0 /2 /a > (-b -x) * 1.0 /2 /a)
                    help(-b + x, 2*a);
                else
                    help(-b - x, 2*a);
                cout << endl;
            }
            else{
                int ans = 1;
                bool flag = 1;
                while (flag){
                    flag = false;
                    for (int i = 2; i * i < t; i++){
                        if (t % (i*i) == 0){
                            ans *= i;
                            flag = 1;
                            t /= i * i;
                            break;
                        }
                    }
                }
                int q2 = ans, q3 = 2*a;
                int h = __gcd(q2, q3);
                q2 /= h;
                q3 /= h;
                if (b != 0) {
                    help(-b, 2*a);
                    cout << "+";
                }
                if (abs(q2) != 1) cout << abs(q2) << "*";
                cout << "sqrt(" << t <<  ")";
                if (abs(q3) != 1) cout << "/" << abs(q3);

                cout << endl;
            }
        }
    }
}
