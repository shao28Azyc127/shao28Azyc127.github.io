#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int T,M;
int gcd(int x,int y){
    if(x > y) gcd(x%y,y);
    if(x < y) gcd(y,x);
    return x;
}
void getlegal(double x, int& p, int& q){
    int cur=2;
    while(1){
        int now = 1.0 * cur * x;
        if(1.0 * now / cur == x){
            p = now;
            q = cur;
            break;
        }
        ++cur;
    }

}
int depress(int x){
    int ans = 1;
    for(int i = 2; i * i <= x; ++i){
        if(x % (i*i) == 0) ans = i;
    }
    return ans;
}
bool have_solve(int a, int b, int c){
    return b * b >= 4 * a * c;
}
void Main(){
    int a,b,c,p,q;
    double ans;

    bool f = false;
    cin >> a >> b >> c;
    if(!have_solve(a,b,c)){
        cout << "NO\n";
        return;
    }
    double delta = b * b - 4 * a * c;
    if((int)sqrt(delta) * (int)sqrt(delta) == delta){
        ans = (-1 * b + sqrt(delta))/(2 * a);
        if((int)ans != ans){
            getlegal(ans,p,q);
            cout << p << '/' << q << endl;
        }
        else cout << (int)ans << endl;
    }
    else{

        if(b != 0){
            if(b % (2*a) == 0) cout << -1 * b / (2*a) << '+';
            else{
                double anst = 1.0 * b / (2*a);
                 getlegal(anst,p,q);
                cout << p << '/' << q << '+';
            }

        }
        if(depress(delta) > 1){
            int de = depress(delta);
            delta = delta / (de*de);
            if(de % (2*a) == 0){
                cout << de/(2*a) << '*';
                f = true;
            }
            else if((2*a) % de == 0){
                int rde = 2 * a / de;
                if(de/rde > 1)
                cout << de/rde << '*';
                a /= rde;
            }
            else cout << de << '*';
        }

        cout << "sqrt(" << delta << ")" ;
        if(!f)cout << '/' << 2 * a << endl;
        else cout << endl;
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> T >> M;
    while(T--) Main();
    return 0;
}
