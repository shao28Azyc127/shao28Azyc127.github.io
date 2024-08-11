#include <bits/stdc++.h>
using namespace std;
int P(int e,int d){
    
    for(int i=2;i<=e;i++){
        if(e%i!=0) continue;
        if(e%i==0){
            if(d%i!=0) continue;
            if(d%i==0) return i;
        }
    }
    return 0;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    for(int i=0;i<T;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int drt=b*b-4*a*c;
        if(drt<0){
            cout<<"NO";
            continue;
        }if(drt==0){
            int t;
            if(b==0) cout<<0;
            while(t){
                t=P(a,b);
                if(t){
                    a/=t;
                    b/=t;
                }if(!t){
                    if(a==1) cout<<b;
                    else if(a<0 && b>0) cout<<a<<'/'<<b;
                    else if(a>0 && b<0) cout<<'-'<<a<<'/'<<0-b;
                    else if(a>0 && b>0) cout<<a<<'/'<<b;
                    else if(a<0 && b<0) cout<<0-a<<'/'<<0-b;
                }
            }
            cout<<"\n";
        }if(drt>0){
            int sd=sqrt(drt);
            if(sd*sd==drt){
                b+=sd;
                int t;
                if(b==0) cout<<0;
                while(t){
                    t=P(a,b);
                    if(t){
                        a/=t;
                        b/=t;
                    }if(!t){
                        if(a==1) cout<<b;
                        else if(a<0 && b>0) cout<<a<<'/'<<b;
                        else if(a>0 && b<0) cout<<'-'<<a<<'/'<<0-b;
                        else if(a>0 && b>0) cout<<a<<'/'<<b;
                        else if(a<0 && b<0) cout<<0-a<<'/'<<0-b;
                    }
                }
                cout<<"\n";
            }
            else{
                int t;
                if(b==0) cout<<0;
                while(t){
                    t=P(a,b);
                    if(t){
                        a/=t;
                        b/=t;
                    }if(!t){
                        if(a==1) cout<<b;
                        else if(a<0 && b>0) cout<<a<<'/'<<b;
                        else if(a>0 && b<0) cout<<'-'<<a<<'/'<<0-b;
                        else if(a>0 && b>0) cout<<a<<'/'<<b;
                        else if(a<0 && b<0) cout<<0-a<<'/'<<0-b;
                    }
                }
                cout<<'+';
                int q2=1;
                for(int i=2;i*i<=drt;i++){
                    if(drt%(i*i)==0){
                        drt/=i*i;
                        q2*=i;
                    }
                }
                if((double)q2/a==1.0){
                    cout<<"sqrt("<<drt<<')';
                }
                int tt;
                while(tt||(a==1 && q2==1)){
                    tt=P(a,q2);
                    if(tt){
                        a/=tt;
                        q2/=tt;
                    }if(!tt){
                        if(a==1 &&q2!=1) cout<<q2<<"*sqrt("<<drt<<')';
                        if(q2==1 && a!=1) cout<<"sqrt("<<drt<<")/"<<a;
                        if(a<0 && q2>0) cout<<a<<'/'<<q2;
                        else if(a>0 && q2<0) cout<<'-'<<a<<'/'<<0-q2;
                        else if(a>0 && q2>0) cout<<a<<'/'<<q2;
                        else if(a<0 && q2<0) cout<<0-a<<'/'<<0-q2;
                    }
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}