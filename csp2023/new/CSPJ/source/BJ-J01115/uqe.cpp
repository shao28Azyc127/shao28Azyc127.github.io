#include<bits/stdc++.h>
using namespace std;
int a,b,c,tmp,w;
int g(int x){
    if(x == 0){
        return 0;
    }
    int ans = 1;
    for(int i = 2;i * i <= x;i++){
        while(x % (i * i) == 0){
            ans *= i;
            x /= i * i;
        }
    }
    return ans;
}
int gcd(int x,int y){
    if(y == 0){
        return x;
    }
    return gcd(y,x % y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    cin >> t >> w;
    while(t--){
        cin >> a >> b >> c;
        if(a < 0){
            a = -a;
            b = -b;
            c = -c;
        }
        tmp = b * b - 4 * a * c;
        int gg = g(tmp);
        if(tmp < 0){
            cout << "NO";
        }else if(gg * gg != tmp){
            if(b != 0){
                int tmp2 = gcd(-b,2 * a);
                if(2 * a / tmp2 < 0){
                    tmp2 = -tmp2;
                }
                if(tmp2 == 2 * a){
                    cout << (-b) / tmp2 << "+";
                }else{
                    cout << (-b) / tmp2 << "/" << 2 * a / tmp2 << "+";
                }
            }
            int q = g(tmp),q2 = 2 * abs(a),t2 = gcd(q,q2);
            tmp /= q * q;
            q /= t2;
            q2 /= t2;
            if(q2 < 0){
                q = -q;
                q2 = -q2;
            }
            if(q == q2 && q2 == 1){
                cout << "sqrt(" << tmp << ")";
            }else if(q2 == 1){
                cout << q << "*sqrt(" << tmp << ")";
            }else if(q == 1){
                cout << "sqrt(" << tmp << ")/" << q2;
            }else{
                cout << q << "*sqrt(" << tmp << ")/" << q2;
            }
        }else{
            int q = gg - b,q2 = 2 * a;
            if(a < 0){
                q = abs(b) + gg;
                q2 = 2 * abs(a);
            }
            int tmp2 = gcd(q,q2);
            q /= tmp2;
            q2 /= tmp2;
            if(q2 < 0){
                q = -q;
                q2 = -q2;
            }
            if(q2 == 1){
                cout << q;
            }else{
                cout << q << "/" << q2;
            }
        }
        cout << '\n';
    }
    return 0;
}
