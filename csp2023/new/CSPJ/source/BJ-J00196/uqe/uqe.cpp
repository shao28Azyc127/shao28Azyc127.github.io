#include <bits/stdc++.h>
using namespace std;
int n,t,vis[1010];
bool prime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return 0;
    }
    return 1;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>t;
    for(int i=2;i<=t;i++)if(prime(i))vis[i]=1;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int beta=b*b-4*a*c;
        if(beta<0)cout<<"NO"<<endl;
        else if(beta==0){
            a=a*-2;
            for(int i=2;i<=min(abs(a),abs(b));i++){
                if(vis[i]==1){
                    while(1){
                        if(abs(a)%i==0&&abs(b)%i==0){
                            a/=i,b/=i;
                        }
                        else break;
                    }}
            }
            if(a<0&&b<0)a=abs(a),b=abs(b);
            if(a<0&&b>0)a=-a,b=-b;
            if(b==0)cout<<0<<endl;
            else if(a==1)cout<<b<<endl;
            else if(a==-1)cout<<-b;
            else cout<<b<<"/"<<a<<endl;
        }
        else{
            a=a*-2;

            int l=1,ax=abs(a);
            for(int i=2;i<=min(abs(a),abs(b));i++){
                if(vis[i]==1){
                    while(1){
                        if(a%i==0&&b%i==0){
                            a/=i,b/=i;
                        }
                        else break;
                    }}}
            for(int i=2;i<=sqrt(beta);i++){
                if(vis[i]==1){
                    while(1){
                        if(beta%(i*i)==0){beta/=(i*i);
                        l*=i;}
                        else break;
                    }
                }
            }
            for(int i=2;i<=min(abs(l),abs(ax));i++){
                if(vis[i]==1){
                    while(1){
                        if(abs(l)%i==0&&abs(ax)%i==0){
                            l/=i,ax/=i;
                        }
                        else break;
                    }}


            }
            if(ax<0||l>0)ax=-ax,l=-l;
            if(a==ax&&beta==1){
                int r=l+b;
                if(r<0||a<0)r=-r,a=-a;
                for(int i=2;i<=min(abs(r),abs(a));i++){
                if(vis[i]==1){
                    while(1){
                        if(abs(r)%i==0&&abs(a)%i==0){
                            r/=i,a/=i;
                        }
                        else break;
                    }}}
                if(a==1)cout<<r<<endl;
                else cout<<r<<"/"<<a<<endl;
             }
             else{
             if(a<0)a=-a,b=-b;
            if(a==1)cout<<b<<"+";
            else if(a==-1)cout<<-b<<"+";
            else if(b!=0)cout<<b<<"/"<<a<<"+";
            if(ax<0)ax=-ax,l=-l;
            if(beta==1&&ax==1)cout<<l<<endl;
            else if(beta==1&&ax!=1)cout<<l<<"/"<<ax<<endl;
            else if(l==1&&ax!=1)cout<<"sqrt("<<beta<<")/"<<ax<<endl;//beta!=1
            else if (ax==1&&l==1)cout<<"sqrt("<<beta<<")"<<endl;//l!=1
            else if(ax==1)cout<<l<<"*sqrt("<<beta<<")"<<endl;//ax!=1
            else cout<<l<<"*sqrt("<<beta<<")/"<<ax<<endl;}}}
    return 0;}