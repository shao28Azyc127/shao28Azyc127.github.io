#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int f1,int f2){
    if(f2==0)return f1;
    return gcd(f2,f1%f2);
}
void youli(int f1,int f2){
    int g=gcd(abs(f1),abs(f2));
    if((f1<0&&f2>0)||(f1>0&&f2<0)){
        cout<<"-";
    }
    f1=abs(f1);
    f2=abs(f2);
    f1/=g,f2/=g;
    if(f2!=1)cout<<f1<<"/"<<f2;
    else cout<<f1;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int ce=b*b-4*a*c;
        if(ce<0){
            cout<<"NO\n";
            continue;
        }
        int l=sqrt(ce);
        if((l+1)*(l+1)==ce)l++;
        if((l-1)*(l-1)==ce)l--;
        if(l*l==ce){
            if(2*a>0)youli(0-b+l,2*a);
            else youli(0-b-l,2*a);
            cout<<endl;
            continue;
        }
        if(b!=0){
            youli(0-b,2*a);
            cout<<"+";
        }
        int t=1;
        for(int i=2;i*i<=ce;i++){
            while(ce%(i*i)==0){
                t*=i;
                ce/=(i*i);
            }
        }
        int f1=t,f2=2*a;
        int g=gcd(abs(f1),abs(f2));
        f1/=g,f2/=g;
        f2=abs(f2);
        if(f1==1&&f2==1){
            cout<<"sqrt("<<ce<<")";
        }
        else if(f2==1){
            cout<<f1<<"*sqrt("<<ce<<")";
        }
        else if(f1==1)cout<<"sqrt("<<ce<<")/"<<f2;
        else cout<<f1<<"*sqrt("<<ce<<")/"<<f2;
        cout<<"\n";
    }
    return 0;
}
