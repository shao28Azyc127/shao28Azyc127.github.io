#include<bits/stdc++.h>
using namespace std;
bool sqtf(int a){
    if(sqrt(a)*sqrt(a)==a) return 1;
    else return 0;
}
bool zctf(int a,int b){
    double x=a,y=b;
    if(a/b==x/b) return 1;
    else return 0;
}
int yf(int a,int b){
    for(int i=min(a,b);i>=2;i--){
        if(zctf(a,i)&&zctf(b,i)) return i;
    }
    return 0;
}
int sq(int a){
    if(sqtf(a)){
        return a;
    }else{
        for(int i=2;i*i<=a;i++){
            if(zctf(a,i)){
                int b=a/i;
                if(sqtf(b)){
                    return b;//返回被开出去的数
                }else continue;
            }else{
                continue;
            }
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cout<<"NO"<<endl;

    }
/*
    for(int i=1;i<=n;i++){
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        double drta=bb*bb-4*aa*cc;
        if(drta<0){
//            cout<<drta<<' ';
            cout<<"NO"<<endl;
        }else{
            double x=(0-bb)+sqrt(drta);
            double y=2*aa;
            cout<<x/y<<endl;
        }
    }
/*    while(nn<=n){
        cin>>a>>b>>c;
        drta=b*b-4*a*c;
        if(drta<0){
            cout<<"NO"<<endl;
        }else{
            x=(0-b)+sqrt(drta);
            y=2*a;
            cout<<x/y<<endl;

            b=0-b;
            if(zctf(b,2*a)){
                x=b/(2*a);
            }else{
                int yfx=yf(b,2*a);
                if(2*a/yfx==1) cout<<b/yfx;
                else cout<<b/yfx<<"/"<<2*a/yfx<<"+";
                xcout=1;
            }
    //----------drta----------
            if(sqtf(drta)==1){//drta是完全平方数
                drta=sqrt(drta);
                if(zctf(drta,2*a)){
                    y=drta/(2*a);
                    if(xcout==1) cout<<"+"<<y<<endl;
                    else cout<<x+y;
                }else{
                    int yfy=yf(drta,2*a);
                    cout<<"+"<<drta/yfy<<"/"<<2*a/yfy;
                }
            }else{//drta不是完全平方数
                if(xcout==0) cout<<x<<"+";
                int sqn=sq(drta);
                int sqout=sqrt(sqn);
                int sqin=drta/sqn;
                if(zctf(sqout,2*a)){
                    if(xcout==0) cout<<x<<"+";
                    if(sqout==2*a){
                        cout<<"sqrt("<<sqin<<")"<<endl;
                    }else{
                        cout<<sqout/(2*a)<<"*sqrt("<<sqin<<")"<<endl;
                    }
                }else{
                    int yfy=yf(sqout,2*a);
                    if(sqout/yfy==1){
                        cout<<"sqrt("<<sqin<<")/"<<2*a/yfy<<endl;
                    }else{
                        cout<<sqout/yfy<<"*sqrt("<<sqin<<")/"<<2*a/yfy<<endl;
                    }
                }
            }
        }
        nn++;
    }*/
    return 0;
}
