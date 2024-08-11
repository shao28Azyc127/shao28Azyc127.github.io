#include <bits/stdc++.h>
using namespace std;

long long t, a, b, c, m, q1a, q1b, q2a, q2b;

long long fun1(long long x){
    long long r = 1;
    for(long long i = 2; i * i <= x; i++){
        if(!(x % i)){
            int t = 0, ti = 1;
            while(!(x % i)){
                x /= i;
                ++t;
                ti *= i;
            }
            if(t & 1) ti /= i;
            r *= ti;
        }
    }
    return r;
}

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while(t--){
        cin >> a >> b >> c;
        long long der = b * b - 4 * a * c;
        if(der < 0){
            cout << "NO\n";
        }else{
            long long x = fun1(der), g;
            der /= x;
            q1a = -b;
            q1b = a << 1;
            if(a > 0){
                q2a = sqrt(x);
                q2b = a << 1;
            }else{
                q2a = sqrt(x);
                q2b = -(a << 1);
            }
            if(q1b < 0){
                q1a = -q1a;
                q1b = -q1b;
            }
            if(q2b < 0){
                q2a = -q2a;
                q2b = -q2b;
            }
            if(der == 1){
                der = 0;
                q1a += q2a;
            }
            g = __gcd(q1a, q1b);
            q1a /= g;
            q1b /= g;
            g = __gcd(q2a, q2b);
            q2a /= g;
            q2b /= g;
            if(q1b < 0){
                q1a = -q1a;
                q1b = -q1b;
            }
            if(q2b < 0){
                q2a = -q2a;
                q2b = -q2b;
            }
            if(q1a){
                if(q1b == 1) cout << q1a;
                else cout << q1a << '/' << q1b;
                if(der) cout << '+';
            }
            if(der){
                if(q2a != 1) cout << q2a << '*';
                cout << "sqrt(" << der << ')';
                if(q2b != 1) cout << '/' << q2b;
            }
            /*
            */
            if(!der && !q1a) cout << 0;
            cout << '\n';
        }
    }
    return 0;
}

