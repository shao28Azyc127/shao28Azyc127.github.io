#include<bits/stdc++.h>
using namespace std;

int t,m,a,b,c,der,k;

int gcd(int x,int y){
    int a = x,b = y;
    while(b != 0){
        a = a % b;
        b = b + a;
        a = b - a;
        b = b - a;
    }
    return abs(a);
}

int gh(int k){
    int i,a = 1,n = k;
    for(i = 2;i < sqrt(n);i++){
        while(n % (i * i) == 0){
            a *= i;
            n /= i * i;
        }
    }
    return a;
}

int print1(int a,int b,bool f){
    int x,y;
    x = a / gcd(a,b);
    y = b / gcd(a,b);
    if(y == 1){
        return x;
    }else if(y == -1){
        return -x;
    }else{
        if(f){
            if(y < 0){
                cout << -x << "/";
                return -y;
            }else{
                cout << x << "/";
            }
        }
        return y;
    }
}

int main(){
    int i,j;

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin >> t >> m;

    while(t--){
        cin >> a >> b >> c;
        der = b * b - 4 * a * c;
        if(der < 0){
            cout << "NO" << endl;
        }else if(der == 0){
            cout << print1(-b,2 * a,true) << endl;
        }else{
            k = sqrt(der);
            if(k * k == der){
                if(a < 0){
                    cout << print1(-b - k,2 * a,true) << endl;
                }else{
                    cout << print1(-b + k,2 * a,true) << endl;
                }
            }else{
                if(print1(-b,2 * a,false) != 0){
                    cout << print1(-b,2 * a,true) << "+";
                }
                if(gh(der) / gcd(gh(der),2 * a) != 1){
                    cout << gh(der) / gcd(gh(der),2 * a) << "*";
                }
                cout << "sqrt(" << der / gh(der) / gh(der) << ")";
                if(2 * a / gcd(gh(der),2 * a) != 1 && 2 * a / gcd(gh(der),2 * a) != -1){
                    cout << "/" << abs(2 * a / gcd(gh(der),2 * a));
                }
                cout << endl;
            }
        }
    }
}