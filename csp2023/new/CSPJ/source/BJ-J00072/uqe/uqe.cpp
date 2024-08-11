#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c;
    int n,m;
    cin>>n>>m;
    for(int cnt = 1; cnt <= n; cnt++){
        cin>>a>>b>>c;
        int delt = b*b-4*a*c;
        if(delt < 0){
            cout<<"NO"<<endl;
            continue;
        }
        if(delt == 0){
            int q = -b;
            int p = 2*a;
            int aq = abs(q);
            int ap = abs(p);
            int gcd = __gcd(ap,aq);
            q /= gcd;
            p /= gcd;
            if(q < 0 &&p < 0){
                q/=-1;
                p/=-1;
            }
            if(p < 0&& q >= 0){
                q = -q;
                p = -p;
            }
            if(p == 1){
                cout<<q<<endl;
            }else{
                cout<<q<<'/'<<p<<endl;
            }
            continue;
        }
        int sq = sqrt(delt);
        if(sq*sq == delt){
            int q = sq-b;
            if(2*a < 0){
                q = -sq-b;
            }else{
                q = sq-b;
            }
            int p = 2*a;
            int aq = abs(q);
            int ap = abs(p);
            int gcd = __gcd(ap,aq);
            q /= gcd;
            p /= gcd;
            if(q < 0 &&p < 0){
                q/=-1;
                p/=-1;
            }
            if(p < 0 && q >= 0){
                q = -q;
                p = -p;
            }
            if(p == 1){
                cout<<q<<endl;
            }else{
                cout<<q<<'/'<<p<<endl;
            }
            continue;
        }
        int q = -b;
        int p = 2*a;
        int aq = abs(q);
        int ap = abs(p);
        int gcd = __gcd(ap,aq);
        q /= gcd;
        p /= gcd;
        if(q < 0 &&p < 0){
            q/=-1;
            p/=-1;
        }
        if(p < 0&& q >= 0){
            q = -q;
            p = -p;
        }
        int k;
        int flg = 0;
        for(int i = sqrt(delt); i >= 2; i--){
            int tmp = i*i;
            if(delt % tmp == 0){
                k = i;
                flg = 1;
                delt /= tmp;
                break;
            }
        }
        if(2*a < 0){
            k = -k;
        }else{
            k = k;
        }
        if(flg == 0){
            if(q == 0){

            }else if(p == 1){
                cout<<q<<'+';
            }else{
                cout<<q<<'/'<<p<<'+';
            }
            if(2*a < 0){
                cout<<"sqrt("<<delt<<")/"<<-2*a<<endl;
            }else{
                cout<<"sqrt("<<delt<<")/"<<2*a<<endl;
            }
            continue;
        }else{
            if(q == 0){

            }else if(p == 1){
                cout<<q<<'+';
            }else{
                cout<<q<<'/'<<p<<'+';
            }
            //cout<<k<<' '<<delt<<endl;
            int kk = k;
            int aa = 2*a;
            int gg = __gcd(abs(kk),abs(aa));
            kk /= gg;
            aa /= gg;
            if(kk < 0 && aa < 0){
                kk = -kk;
                aa = -aa;
            }
            if(aa < 0){
                aa = -aa;
            }
            if(aa == 1){
                if(kk == 1){
                    cout<<"sqrt("<<delt<<")"<<endl;
                }else{
                    cout<<kk<<"*sqrt("<<delt<<")"<<endl;
                }
                continue;
            }
            if(kk == 1){
                cout<<"sqrt("<<delt<<")/"<<aa<<endl;
            }else{
                cout<<kk<<"*sqrt("<<delt<<")/"<<aa<<endl;
            }
        }
    }
    return 0;
}
