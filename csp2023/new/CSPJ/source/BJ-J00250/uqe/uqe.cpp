#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c,itg,drt;
void lft(int b,int a){
    for(int i = 2;i <= min(abs(a),abs(b));i++){
        while(abs(a) % i == 0 && abs(b) % i == 0){
            a /= i;
            b /= i;
        }
    }
    if(b > 0 && a < 0){
        b = -1 * b;
        a = -1 * a;
    }
    if(abs(a) == 1) cout << b * a;
    else cout << b << '/' << a;
}
void rgt(int drt,int a){
    if(drt != 1){
        for(int i = 2;i <= min(abs(a),abs(itg));i++){
            while(a % i == 0 && itg % i == 0){
                a /= i;
                itg /= i;
            }
        }
        if(itg != 1)cout << abs(itg) << '*';
        cout << "sqrt(" << drt << ")";
        if(abs(a) != 1) cout << '/' << abs(a);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    while(t--){
        cin >> a >> b >> c;
        drt = b * b - 4 * a * c;
        if(drt < 0) cout << "NO" << endl;
        else{
            itg = 1;
            for(int i = 2;i * i <= drt;i++){
                while(drt % (i * i) == 0){
                    itg *= i;
                    drt /= i * i;
                }
            }
            if(drt == 1 && (1.0 * itg - b) / (2 * a) != 0) lft(abs(a) / a * itg - b,2 * a);
            else if(-1.0 * b / (2 * a) != 0){
                lft(-1 * b,2 * a);
                if(drt != 0 && drt != 1) cout << '+';
            }
            if(drt != 0 && drt != 1) rgt(drt,2 * a);
            cout << endl;
        }
    }


    return 0;
}
