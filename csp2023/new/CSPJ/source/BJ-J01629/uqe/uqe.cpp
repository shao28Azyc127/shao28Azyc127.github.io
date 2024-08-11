#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int K,r1;
    cin >> K >> r1;
    while(K--){
        int a,b,c;
        cin >> a >>b >> c;
        if(b*b<4*a*c) cout <<"NO";
        else if(b*b==4*a*c){
            if(b%(2*a)==0){
                cout << -b/(2*a);
            }
            else{
                a*= 2;
                int gd = gcd(max(a,b),min(a,b));
                cout << -b/gd <<"/" << a/gd;
            }
        }else{
            int delta = b*b - 4* a* c;
            double s_d = sqrt(delta);
            if(s_d == int(s_d)){
                b = s_d - b;
                if(b%(2*a)==0){
                    cout << b/(2*a);
                }
                else{
                    a*=2;
                    int gd = gcd(max(a,b),min(a,b));
                    cout << b/gd <<"/" << a/gd;
                }
            }
        }

    }
    return 0;
}
