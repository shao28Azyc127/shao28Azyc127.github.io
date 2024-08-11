#include<bits/stdc++.h>
using namespace std;
void onestep(){
    int a, b, c; cin >> a >> b >> c;
    if(c==0){
        if(a*b<0){
            if(a<0) a=-a;
            else b=-b;
            a/=__gcd(a,b);
            b/=__gcd(a,b);
            if(a == 1) cout << b << endl;
            else cout << b << "/" << a << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        if(b*b-4*a*c<0){
            cout << "NO" << endl;
        }else{
            cout << (-b+sqrt(b*b-4*a*c))/(2*a) << endl;
        }
    }
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m; cin >> t >> m;
    while(t--) onestep();
    return 0;
}
