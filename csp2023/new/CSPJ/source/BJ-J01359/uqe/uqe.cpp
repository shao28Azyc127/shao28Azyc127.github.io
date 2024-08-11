#include<bits/stdc++.h>
using namespace std;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(b*b-4*a*c<0){
            cout << "NO";
            continue;
        }
        else{
            if(sqrt(b*b-4*a*c)*sqrt(b*b-4*a*c)==b*b-4*a*c){
                if((-b+(int)sqrt(b*b-4*a*c))%(2*a)==0)
                    cout << (-b+sqrt(b*b-4*a*c))/(2*a);
                else{
                    if(-b+(int)sqrt(b*b-4*a*c)<0&&2*a>0||-b+(int)sqrt(b*b-4*a*c)>0&&2*a<0)
                        cout << '-' << abs((-b+(int)sqrt(b*b-4*a*c))/__gcd(-b+(int)sqrt(b*b-4*a*c),2*a)) << "/" << abs(2*a/__gcd(-b+(int)sqrt(b*b-4*a*c),2*a));
                    else
                        cout << (-b+(int)sqrt(b*b-4*a*c))/__gcd(-b+(int)sqrt(b*b-4*a*c),2*a) << "/" << 2*a/__gcd(-b+(int)sqrt(b*b-4*a*c),2*a);
                }
            }
            else{
                if((-b)%(2*a)==0){
                    cout << -b/(2*a) << "+sqrt(" << b*b-4*a*c << ")" << "/" << 2*a;
                }
                else{
                    cout << -b << "/" << 2*a << "+sqrt(" << b*b-4*a*c << ")" << "/" << 2*a;
                }
            }
        }
    }
    return 0;
}
