#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int gcd(int x,int y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    return gcd(y,x%y);
}
void q(int x,int y){
    if(y%x==0){
        cout<<y/x;
    }
    else{
        int num=gcd(abs(x),abs(y));
        cout<<(y/num)<<"/"<<x/num;
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        if(a<0){
            a=-a; b=-b; c=-c;
        }
        bool flag=0;
        int delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
            continue;
        }
        int mx=0;
        for(int j=1;j*j<=delta;j++){
            if(delta%(j*j)==0) mx=j;
        }
        if(mx*mx==delta){
            q(2*a,-b+mx);
            cout<<endl;
            continue;
        }
        if(b!=0){
            q(2*a,-b);
            flag=1;
        }
        if(delta!=0){
            if(flag) cout<<"+";
            if(mx==1){
                cout<<"sqrt("<<delta<<")/"<<2*a;
            }
            else{
                delta/=(mx*mx);
                if(mx%(2*a)==0){
                    if(mx/(2*a)==1) cout<<"sqrt("<<delta<<")";
                    else cout<<mx/(2*a)<<"*sqrt("<<delta<<")";
                }
                else{
                    int g=gcd(2*a,mx);
                    if(mx/g==1) cout<<"sqrt("<<delta<<")/"<<2*a/g;
                    else cout<<mx/g<<"*sqrt("<<delta<<")/"<<2*a/g;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
