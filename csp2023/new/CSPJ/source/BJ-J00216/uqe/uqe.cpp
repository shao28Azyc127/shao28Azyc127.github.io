#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int gcd(int x,int y){
    if(x>y) swap(x,y);
    if(x==0) return y;
    return gcd(x,y%x);
}
void print(int x,int y){
    if(x==0) return ;
    int gc=gcd(abs(x),abs(y));
    x/=gc,y/=gc;
    if(x*y<0) cout<<"-";
    cout<<abs(x);
    if(abs(y)!=1) cout<<"/"<<abs(y);
}
void print1(int x,int zj,int y){
    if(x==0) return ;
    int gc=gcd(abs(x),abs(y));
    x/=gc,y/=gc;
    if(x*y<0) cout<<"-";
    if(abs(x)!=1) cout<<abs(x)<<"*";
    cout<<"sqrt("<<zj<<")";
    if(abs(y)!=1) cout<<"/"<<abs(y);
}
int tichu(int x){
    int mx=0;
    for(int i=1;i*i<=x;i++){
        if(x%(i*i)==0){
            mx=i;
        }
    }
    return mx;
}
void work(){
    cin>>a>>b>>c;
    int del=b*b-4*a*c;
    if(del<0){
        cout<<"NO"<<endl;
        return ;
    }
    int fz1=-b;
    int fm1=a*2;
//    int gd=gcd(abs(a),abs(b));
//    fz1/=gd,fm1/=gd;
//    print(fz1,fm1);
    int tc=tichu(del);
    if(del==0){
        print(fz1,fm1);
        if(fz1==0) cout<<0;
        cout<<endl;
        return ;
    }
    del/=tc;
    del/=tc;
    if(del==1){
        if(a>0) fz1+=tc;
        else fz1-=tc;
        print(fz1,fm1);
        if(fz1==0) cout<<0;
        cout<<endl;
        return ;
    }
    print(fz1,fm1);
    int fz2=tc;
    if(a<0) fz2=-tc;
    int fm2=a*2;
    if(fz1!=0&&(fm2*fz2>0)){
        cout<<"+";
    }
    print1(fz2,del,fm2);
    if(fz1==0&&fz2==0) cout<<0;
    cout<<endl;
    return ;
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--) work();
    return 0;
}
