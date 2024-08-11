#include<bits/stdc++.h>
using namespace std;

bool flag1=0,flag2=0,flag3=0;
int p[1005];
int a,b,c,x=1,d;
int aa,bb,cc;

void init(){
    for(int i=2;i<=1000;i++){
        p[i]=i*i;
    }
}

int gcd(int y,int z){
    if(y%z==0) return z;
    else return gcd(z,y%z);
}

void youli(int u,int v,int w,int id){
    if(id==1){
        int g=gcd(v,u);
        u/=g;
        v/=g;
        cout<<u<<"/"<<v;
    }
    if(id==2){
        int g=gcd(v,u);
        u/=g;
        v/=g;
        if(u==1&&v!=1) cout<<"sqrt("<<d<<")"<<"/"<<v;
        else if(v==1&&u!=1) cout<<u<<"*sqrt("<<d<<")";
        else if(v==1&&u==1) cout<<"sqrt("<<d<<")";
        else cout<<u<<"*sqrt("<<d<<")"<<"/"<<v;
    }
}
int del(int a,int b,int c){
    return (b*b)-(4*a*c);
}
void ot(){
    if(flag1==1){
        if(a>0)x=x-b;
        if(a<0)x=-x-b;
        if(x*a<0) cout<<"-";
        if(x<0) x=-x;
        if(x%(2*aa)==0) cout<<x/(aa*2);
        else{
            youli(x,2*aa,0,1);
        }
        return;
    }
    if(flag2==1){
        if(b!=0){
            if(a*b>0) cout<<"-";
            cout<<bb/(aa*2);
        }
        if(b!=0)cout<<"+";
        youli(x,2*aa,d,2);
        return;
    }
    if(flag3==1){
        if(b!=0){
            if(a*b>0) cout<<"-";
            youli(bb,2*aa,0,1);
        }
        if(b!=0) cout<<"+";
        if(x/(aa*2)==1){
            cout<<"sqrt("<<d<<")";
            return;
        }
        cout<<x/(aa*2);
        cout<<"*sqrt("<<d<<")";
        return;
    }
    if(a*b>0) cout<<"-";
    youli(bb,2*aa,0,1);
    if(b!=0)cout<<"+";
    youli(x,2*aa,d,2);
    return;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    init();
    int n,m;
    cin>>n>>m;
    while(n--){
        x=1;
        flag1=0;
        flag2=0;
        flag3=0;
        cin>>a>>b>>c;
        if(a<0) aa=-a;
        else aa=a;
        if(b<0) bb=-b;
        else bb=b;
        if(c<0) cc=-c;
        else cc=c;
        d=del(a,b,c);
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        int s=sqrt(d);
        if(s*s==d){
            x=sqrt(d);
            flag1=1;
        }
        else {
            for(int i=1000;i>=2;i--){
                if(d%p[i]==0){
                d/=p[i];
                x*=i;
                }
            }
        }
        if(bb%(aa*2)==0) flag2=1;
        if(x%(aa*2)==0) flag3=1;
        ot();
        cout<<endl;
 //       cout<<flag3;
 //       cout<<x<<" "<<2*aa<<" "<<gcd(2*aa,x)<<endl;
    }
    return 0;
}
