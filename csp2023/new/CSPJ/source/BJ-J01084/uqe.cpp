#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int f(int x){
    int ret = 0;
    for (int i = 1;i * i <= x;i++){
        if (x % (i * i) == 0) ret = i;
    }
    return ret;
}
int gcd(int x,int y){
    if (y == 0){
        return x;
    }
    return gcd(y,x % y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    for (int i = 1;i <= t;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if (a < 0){
            a *= -1;
            b *= -1;
            c *= -1;
        }
        int d = b * b - 4 * a * c;
        if (d < 0){
            cout << "NO" << endl;
        }
        else{
            int e = f(d);
            if (e * e == d){
                int p = e - b,q = 2 * a;
                int g = gcd(abs(p),abs(q));
                p /= g;
                q /= g;
                if (q < 0){
                    p *= -1;
                    q *= -1;
                }
                if (q == 1){
                    cout << p << endl;
                }
                else{
                    cout << p << '/' << q << endl;
                }
            }
            else{
                int f = d / e / e;
                if (b == 0){
                    int p = e,q = 2 * a;
                    int g = gcd(abs(p),abs(q));
                    p /= g;
                    q /= g;
                    if (q < 0){
                        p *= -1;
                        q *= -1;
                    }
                    if (p != 1){
                        cout << p << '*';
                    }
                    cout << "sqrt(" << f << ")";
                    if (q != 1){
                        cout << '/' << q;
                    }
                    cout << endl;
                }
                else{
                    int p = -b,q = 2 * a;
                    int g = gcd(abs(p),abs(q));
                    p /= g;
                    q /= g;
                    if (q < 0){
                        p *= -1;
                        q *= -1;
                    }
                    if (q == 1){
                    cout << p;
                    }
                    else{
                        cout << p << '/' << q;
                    }
                    cout << "+";


                    p = e,q = 2 * a;
                    g = gcd(abs(p),abs(q));
                    p /= g;
                    q /= g;
                    if (q < 0){
                        p *= -1;
                        q *= -1;
                    }
                    if (p != 1){
                        cout << p << '*';
                    }
                    cout << "sqrt(" << f << ")";
                    if (q != 1){
                        cout << '/' << q;
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
