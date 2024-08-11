#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int t,m;
long long a,b,c,dt;
long long gcd(long long e,long long f){
    if(f==0)return e;
    else return gcd(f,e%f);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    while(t--){
        cin >> a >> b >> c;
        dt=b*b-4*a*c;
        if(dt<0){
            cout << "NO\n";
            continue;
        }
        long long sq=sqrt(dt);
        if(sq*sq==dt){
            b=-b;
            a*=2;
            if(a<0){
                a=-a;
                b=-b;
            }
            b+=sq;
            long long g=gcd(a,b);
            if(g<0)g=-g;
            a/=g;
            b/=g;
            if(a==1){
                cout << b << endl;
            }
            else{
                cout << b << "/" << a << endl;
            }
        }
        else{
            long long q=a*2,p=1;
            b=-b;
            a*=2;
            if(a<0){
                a=-a;
                b=-b;
            }
            long long g=gcd(a,b);
            if(g<0)g=-g;
            b/=g;
            a/=g;
            if(b){
                if(a==1){
                    cout << b << "+";
                }
                else{
                    cout << b << "/" << a << "+";
                }
            }
            for(int i = 2;i*i<= dt;i++){
                while(dt%(i*i)==0){
                    dt/=(i*i);
                    p*=i;
                }
            }
            g=gcd(q,p);
            q/=g;
            p/=g;
            if(q<0){
                q=-q;
            }
            if(p<0){
                p=-p;
            }
            if(q==1 && p==1){
                cout << "sqrt(" << dt << ")\n";
            }
            else if(q==1){
                cout << p << "*sqrt(" << dt << ")\n";
            }
            else if(p==1){
                cout << "sqrt(" << dt << ")/" << q << endl;
            }
            else{
                cout << p << "*sqrt(" << dt << ")/" << q << endl;
            }
        }
    }
    return 0;
}
