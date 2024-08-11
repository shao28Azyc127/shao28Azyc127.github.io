#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long t,m,a,b,c,del,p,q,tmp,power[5005];
long long gcd(long long x,long long y){
    if(x<y) swap(x,y);
    return (y==0)?x:gcd(y,x%y); //warn:y.init=0 leads to trouble
}
void change(long long &x,long long &y){
    tmp=gcd(abs(p),abs(q));
    if(q<0) {q=-q; p=-p;}
    p/=tmp; q/=tmp;
}
long long change2(long long &del){
    long long res=1;
    for(int i=2;power[i]<=del;i++){
        while(del%power[i]==0){
            res*=i; del/=power[i];
        }
    }
    return res;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    for(long long i=2;i<=5000;i++) power[i]=i*i;
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        del=(b*b)-(4*a*c);
        if(del<0) {cout<<"NO"<<endl; continue;}
        if((long long)sqrt(del)*sqrt(del)==del){
            if(a>0){
                p=-b+sqrt(del); q=2*a;
            }
            if(a<0){
                p=-b-sqrt(del); q=2*a;
            }
            change(p,q);
            if(q!=1) cout<<p<<"/"<<q<<endl;
            if(q==1) cout<<p<<endl;
        }
        else{
            if(b!=0){
                p=-b; q=2*a;
                change(p,q);
                if(q!=1) cout<<p<<"/"<<q;
                if(q==1) cout<<p;
                cout<<'+';
            }
            p=change2(del); q=2*a;
            if(a<0) p=-p;
            change(p,q);
            if(p==q) cout<<"sqrt("<<del<<")";
            else if(q==1) cout<<p<<"*sqrt("<<del<<")";
            else if(p==1) cout<<"sqrt("<<del<<")/"<<q;
            else cout<<p<<"*sqrt("<<del<<")/"<<q;
            cout<<endl;
        }
    }
}
