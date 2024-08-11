#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int t, m, a, b, c;
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
cin >> t >> m;
    while(t--){
        cin >> a >> b >> c;
        if((b * b - 4 * a * c) < 0){
            cout << "NO\n";
        } else{
            if((-b + (a > 0 ? 1 : -1) *  sqrt((b * b - 4 * a * c))) / (2 * a) == (int)(-b + (a > 0 ? 1 : -1) * sqrt((b * b - 4 * a * c))) / (2 * a)) cout << (int)(-b + (a > 0 ? 1 : -1) * sqrt((b * b - 4 * a * c))) / (2 * a) << "\n";
            else {
                // diyiduan
                int d = b * b - 4 *a *c;
                int p = 1;
                for(int i = 2; i * i <= d; i++){
                    while(d % (i * i) == 0){
                        d /= i * i;
                        p *= i;
                    }
                }
                p *= (a > 0 ? 1 : -1);
                //dierduan
                if(d == 0){
                        int f = __gcd(b, 2 * a);
                    int flag = 1;
                    if(b != 0){
                        flag = 0;
                        if(2 * a / f == 1){
                            cout << (int)-b / f;
                        } else{
                            if(-b/f < 0 && 2 * a / f < 0)
                                cout << b / f << "/" << -2 *a / f;
                            else
                                cout << -b / f << "/" << 2 *a / f;
                        }
                    }
                    cout << "\n";
                    continue;
                } else if(d == 1){
                    b -= p;
                    int f = __gcd(b, 2 * a);
                    int flag = 1;
                    if(b != 0){
                        if(2 * a / f == 1){
                            cout << (int)-b / f;
                        } else{
                            if(-b/f < 0 && 2 * a / f < 0)
                                cout << b / f << "/" << -2 *a / f;
                            else
                                cout << -b / f << "/" << 2 *a / f;
                        }
                        cout << "\n";
                    } else{
                        cout << "0\n";
                    }
                } else{
                    int f = __gcd(b, 2 * a);
                    int flag = 1;
                    if(b != 0){
                        flag = 0;
                        if(2 * a / f == 1){
                            cout << (int)-b / f;
                        } else{
                            if(-b/f < 0 && 2 * a / f < 0)
                                cout << b / f << "/" << -2 *a / f;
                            else
                                cout << -b / f << "/" << 2 *a / f;
                        }
                    }
                    if(d == 0 && p / __gcd(p, 2 * a) ==1){
                        cout << "\n";
                        continue;
                    }
                    if(flag == 0) cout << "+";
                    if ( p / __gcd(p, 2 * a) != 1)cout << abs(p / __gcd(p, 2 * a)) <<"*";
                    cout << "sqrt(" << d << ")";
                    if ( 2 * a / __gcd(p, 2 * a) != 1)cout  << "/"<< abs(2 * a / __gcd(p, 2 * a));
                    cout<< "\n";
                }
            }
        }
    }
    return 0;
}
