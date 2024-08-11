#include <bits/stdc++.h>
using namespace std;
int t,m;
int gcd(int x,int y){
    while(x!=0 && y!=0){
        if(x>y){
            x=x%y;
        }
        else{
            y=y%x;
        }
    }
    if(x==0){
        return y;
    }
    return x;
}
int sq(int x){
    for(int i=sqrt(x);i>=1;i--){
        if(x%(i*i)==0){
            return i;
        }
    }
    return 1;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t>>m;
    for(int z=1;z<=t;z++){
        int a,b,c;
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        int de=sqrt(d);
        if(de*de==d){
            int ax=de-b,a2=2*a;
            if(ax*a2<0){
                cout<<"-";
            }
            ax=abs(ax);
            a2=abs(a2);
            if(ax%a2==0){
                cout<<ax/a2<<endl;
            }
            else{
                int g=gcd(ax,a2);
                ax=ax/g;
                a2=a2/g;
                cout<<ax<<"/"<<a2<<endl;
            }
            continue;
        }
        a=a*2;
        b=-b;
        int s=sq(d);
        d=d/(s*s);
        if(b*a<0 && b!=0){
            cout<<"-";
        }
        int bb=abs(b);
        int aa=abs(a);
        if(bb%aa==0 && b!=0){
            cout<<bb/aa;
        }
        else if(b!=0){
            int g=gcd(aa,bb);
            bb=bb/g;
            aa=aa/g;
            cout<<bb<<"/"<<aa;
        }
        if(b!=0){
            cout<<"+";
        }
        a=abs(a);
        s=abs(s);
        if(s==a){
            cout<<"sqrt("<<d<<")";
        }
        else if(s%a==0){
            cout<<s/a<<"*sqrt("<<d<<")";
        }
        else{
            int g=gcd(a,s);
            a=a/g;
            s=s/g;
            if(s!=1){
                cout<<s<<"*";
            }
            cout<<"sqrt("<<d<<")/"<<a;
        }
        cout<<endl;
    }
    return 0;
}