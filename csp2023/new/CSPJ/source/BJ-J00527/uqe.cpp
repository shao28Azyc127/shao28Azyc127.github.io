#include <iostream>
#include <cmath>
using namespace std;

int t,m;
int a,b,c;
int delta;
int sqrtd;

int gcd(int a,int b){
    int ans = 1;
    if (a > b) swap(a,b);
    for (int i = 1;i <= sqrt(a);i++){
        while (a%i==0&&b%i==0&&i!=1){
            ans *= i;
            a/=i;b/=i;
        }
        int y = a/i;
        if (a%y==0 && b%y==0){
            ans *= y;
            a/=y;b/=y;
        }
    }
    return ans;
}

int func(int x){
    int ans = 1;
    for (int i = 1;i*i <= x;i++){
        if (x%(i*i)==0) ans = i;
    }
    return ans;
}

void print(int a,int b){
    if (a == 0){
        cout << 0;
        return;
    }
    int fuhao = (a*b)/abs(a*b);
    int x = gcd(abs(a),abs(b));
    a = a/x;
    b = b/x;
    if (fuhao == -1) cout << "-";
    if (abs(b) == 1) {
        cout << abs(a);
    }else cout << abs(a) << "/" << abs(b);
}

void print2(int a,int b,int d){
    if (a == b) cout << "sqrt(" << d << ")";
    else if (b == 1) cout << a << "*" << "sqrt(" << d << ")";
    else if (a == 1) cout << "sqrt(" << d << ")/" << b;
    else cout << a << "*" << "sqrt(" << d << ")/" << b;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    while (t--){
        cin >> a >> b >> c;
        delta = b*b - 4*a*c;
        sqrtd = (int)sqrt(delta);
        if (delta < 0){
            cout << "NO\n";
        }else{
            if (sqrtd*sqrtd == delta){
                if (a < 0) print(-sqrtd-b,2*a);
                else print(sqrtd-b,2*a);
                cout << endl;
            }
            else{
                if (b != 0) {
                    print(-b,2*a);
                    cout << "+";
                }
                int x = func(delta);
                int r = gcd(x,abs(a*2));
                print2(x/r,abs(2*a)/r,delta/(x*x));
                cout << endl;
            }
        }
    }
    return 0;
}
