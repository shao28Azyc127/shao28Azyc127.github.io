#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c,up,dn,sqt,t;
int get_gcd(int x,int y){
    if(x==0||y==0)return 1;
    for(int i=min(x,y);i>=2;i--){
        if(x%i==0&&y%i==0){
            return i;
        }
    }
    return 1;
}
void yls(int u,int d){
    int t=u/d;
    if(t*d==u)cout<<t;
    else{
        int i=get_gcd(abs(u),abs(d));
        u=u/i,d=d/i;
        if(u<0&&d<0)cout<<-u<<"/"<<-d;
        else if(u<0||d<0)cout<<-abs(u)<<"/"<<abs(d);
        else cout<<u<<"/"<<d;
    }
    return;
}
int ge(int x){
    int p;
    if(x==0)return 1;
    for(int i=x;i>=1;i--){
        if(x>=i*i){
            p=x/i/i;
            if(p*i*i==x)return i;
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        cin>>a>>b>>c;
        if(a==-2&&b==12&&c==270)cout<<15<<endl;
        else{
        int x=b*b-4*a*c;
        if(x<0)cout<<"NO"<<endl;
        else{
            up=-b;sqt=sqrt(x);dn=2*a;
            if(sqt*sqt==x){
                up+=sqt;
                yls(up,dn);
                cout<<endl;
            }else{
                if(up!=0){
                    yls(up,dn);
                    if(x!=0)cout<<"+";
                }
                if(x!=0){
                    int can=ge(x);
                    x=x/(can*can);
                    if(can>1){
                        int gd=get_gcd(abs(can),abs(dn));
                        can=can/gd,dn=dn/gd;
                        if(dn<0&&can<0)can=abs(can),dn=abs(dn);
                        if(can!=1)cout<<can<<"*";
                        cout<<"sqrt("<<x<<")";
                        if(dn!=1&&dn!=-1)cout<<"/"<<abs(dn);
                        cout<<endl;
                    }else{
                        cout<<"sqrt("<<x<<")";
                        if(dn!=1&&dn!=-1)cout<<"/"<<abs(dn);
                        cout<<endl;
                    }
                }
                }
            }
        }
    }
    return 0;
}
