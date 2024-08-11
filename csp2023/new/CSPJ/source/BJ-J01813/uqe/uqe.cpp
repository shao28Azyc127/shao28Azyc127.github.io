#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c;
int gcd(int x,int y){
    if(x * y == 0) return x + y;
    return gcd(y,x % y);
}
bool isp(int x){
    int s = sqrt(x);
    if(s * s == x) return true;
    else return false;
}
int maxcan(int x){
    int s = sqrt(x);
    while(s){
        int p = s * s;
        if(x % p == 0) break;
        s--;
    }
    return s;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> T >> M;
    while(T--){
        cin >> a >> b >> c;
        int aa = a;
        int bb = b;
        int cc = c;
        int dt = b * b - 4 * a * c;
        if(dt < 0){
            cout << "NO" << endl;
            continue;
        }
        if(dt == 0){
            if(a * b < 0){
                a = 2 * abs(a),b = abs(b);
                cout << b / gcd(a,b);
                if(a / gcd(a,b) != 1) cout << "/" << a / gcd(a,b);
                cout << endl;
                continue;
            }
            if(a * b == 0){
                cout << 0 << endl;
                continue;
            }
            if(a * b > 0){
                cout << "-";
                a = 2 * abs(a),b = abs(b);
                cout << b / gcd(a,b);
                if(a / gcd(a,b) != 1) cout << "/" << a / gcd(a,b);
                cout << endl;
                continue;
            }
        }
        if(dt > 0){
            if(isp(dt)){
                dt = sqrt(dt);
                b = dt - b;
                if(a * b < 0){
                    cout << "-";
                    a = 2 * abs(a),b = abs(b);
                    cout << b / gcd(a,b);
                    if(a / gcd(a,b) != 1) cout << "/" << a / gcd(a,b);
                    cout << endl;
                    continue;
                }
                if(a * b > 0){
                    a = 2 * abs(a),b = abs(b);
                    cout << b / gcd(a,b);
                    if(a / gcd(a,b) != 1) cout << "/" << a / gcd(a,b);
                    cout << endl;
                    continue;
                }
                if(a * b == 0){
                    cout << 0 << endl;
                    continue;
                }
            }
            else{
                int mc = maxcan(dt);
                if(mc == 1){
                    bool flag = true;
                    if(a * b > 0){
                        cout << "-";
                        a = 2 * abs(a),b = abs(b);
                        cout << b / gcd(a,b);
                        if(a / gcd(a,b) != 1) cout << "/" << a / gcd(a,b);
                    }
                    else if(a * b == 0) flag = false;
                    else{
                        a = 2 * abs(a),b = abs(b);
                        cout << b / gcd(a,b);
                        if(a / gcd(a,b) != 1) cout << "/" << a / gcd(a,b);
                    }
                    a = aa;
                    b = bb;
                    c = cc;
                    if(a > 0 && flag) cout << "+";
                    if(a < 0) cout << "-";
                    cout << "sqrt(" << dt << ")/" << 2 * abs(a) << endl;
                    continue;
                }
                else{
                    dt = dt / mc / mc;
                    bool flag = true;
                    if(a * b > 0){
                        cout << "-";
                        a = 2 * abs(a),b = abs(b);
                        cout << b / gcd(a,b);
                        if(a / gcd(a,b) != 1) cout << "/" << a / gcd(a,b);
                    }
                    else if(a * b == 0) flag = false;
                    else{
                        a = 2 * abs(a),b = abs(b);
                        cout << b / gcd(a,b);
                        if(a / gcd(a,b) != 1) cout << "/" << a / gcd(a,b);
                    }
                    a = aa;
                    b = bb;
                    c = cc;
                    if(a > 0 && flag) cout << "+";
                    if(a < 0) cout << "-";
                    a = 2 * abs(a);
                    if(mc / gcd(mc,a) != 1) cout << mc / gcd(mc,a) << "*";
                    cout << "sqrt(" << dt << ")";
                    if(a / gcd(mc,a) != 1) cout << "/" << a / gcd(mc,a);
                    cout << endl;
                    continue;
                }
            }
        }
    }
    return 0;
}