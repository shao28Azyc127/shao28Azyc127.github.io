#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return gcd(b%a,a);
}void yls(int a,int b){
    //cout<<a<<" "<<b<<endl;
    if(a==0)cout<<0;
    else{
        int tt=1,pp=1;
        if(a<0)tt=-1;
        if(b<0)pp=-1;
        a=abs(a);
        b=abs(b);
        int tp=gcd(a,b);
        a/=tp,b/=tp;
        if(tt*pp==-1)cout<<'-';
        if(b==1)cout<<a;
        else cout<<a<<"/"<<b;
    }
}signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int tt,m,a,b,c,t;
    cin>>tt>>m;
    while(tt--){
        cin>>a>>b>>c;
        t=b*b-4*a*c;
        if(t<0)cout<<"NO\n";
        else{
            if((double)(100000)*sqrt((double)(t))-100000*b>0-(double)(100000)*sqrt((double)(t))-b)yls((double)(100000)*sqrt((double)(t))-100000*b,200000*a);
            else yls(0-(double)(100000)*sqrt((double)(t))-100000*b,200000*a);
            cout<<endl;
        }
    }return 0;
}
