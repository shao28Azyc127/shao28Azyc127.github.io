#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(!b)return a;
    else return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c,delta,g,pows[2304];
    cin >> t >> m;
    for(int i = 0;i < sqrt(5*m*m);++i){
        pows[i] = i*i;
    }
    for(int i = 0;i < t;++i){
        cin >> a >> b >> c;
        delta = b*b-4*a*c;
        if(delta<0)cout << "NO" << endl;
        else{
            if(sqrt(delta) == (int)sqrt(delta)){
                if((-b+(int)sqrt(delta))%(2*a)==0){
                    cout << (-b+sqrt(delta))/(2*a) << endl;
                }
                else{
                    g = gcd(-b+sqrt(delta),2*a);
                    if((2*a)/g < 0 && (-b+sqrt(delta))/g > 0){
                        cout << -(-b+sqrt(delta))/g << "/" << -(2*a)/g << endl;
                    }else{
                        cout << (-b+sqrt(delta))/g << "/" << (2*a)/g << endl;
                    }
                }
            }else{
                if((-b)/(2*a) != 0){
                    if((-b)/(2*a) == (int)((-b)/(2*a))){
                        cout << (-b)/(2*a) << "+";
                    }else{
                        g = gcd(-b,2*a);
                        if((2*a)/g < 0 && (-b)/g > 0){
                            cout << -(-b)/g << "/" << -(2*a)/g << "+";
                        }else{
                            cout << (-b)/g << "/" << (2*a)/g << "+";
                        }
                    }
                }
                double q,q2 = 1.0/(2*a);
                for(int j = (int)sqrt(5*m*m);j > 0;j--){
                    if(delta%(j*j) == 0){
                        q = j;
                        q2 *= j;
                        delta /= j*j;
                        break;
                    }
                }
                if(q2 < 0)q2 = -q2;
                if(q2 == 1)cout << "sqrt(" << delta << ")" << endl;
                else if(q2 == int(q2))cout << q2 << "*sqrt(" << delta << ")" << endl;
                else if(1/q2 == int(1/q2))cout << "sqrt(" << delta << ")/" << 1/q2 << endl;
                else{
                    g = gcd(q,2*a);
                    cout << q/g << "*sqrt(" <<delta << ")/" << 2*a/g << endl;
                }
            }
        }
    }
    return 0;
}
