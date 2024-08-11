#include<bits/stdc++.h>
using namespace std;
int main(void){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c,delta,t,m;
    cin >> t >> m;
    for(int kase=0;kase<t;kase++){
        cin >> a >> b >> c;
        delta=(b*b)-(4*a*c);
        if(delta<0){
            cout << "NO";
        }
        else if(0 == delta){
            if((-b - sqrt(delta))/double(2*a) == (-b - sqrt(delta))/2*a){
                cout << (-b - sqrt(delta))/2*a;
            }
            else cout << (-b - sqrt(delta)) << '/' << 2*a;
        }
        else{
            if(max(-b - sqrt(delta),-b + sqrt(delta))/double(2*a) == max(-b - sqrt(delta),-b + sqrt(delta))/2*a){
                cout << max(-b - sqrt(delta),-b + sqrt(delta))/2*a;
            }
            else cout << max(-b - sqrt(delta),-b + sqrt(delta)) << '/' << 2*a;
        }
        cout << '\n';
    }
    return 0;
}
