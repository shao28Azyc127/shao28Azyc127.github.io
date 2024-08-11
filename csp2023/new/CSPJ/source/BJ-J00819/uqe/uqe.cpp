#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int newceil(int n,int m){
    if(n%m==0) return n/m;
    return n/m+1;
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T=read(),m=read();
    while(T--){
        int a=read(),b=read(),c=read();
        if(b*b-4*a*c<0) cout<<"NO\n";
        else if(b*b-4*a*c==0){
            int g=gcd(b,2*a);
            if(2*a/g<0) a*=-1,b*=-1;
            cout<<b/g;
            if(2*a/g!=1) cout<<'/'<<2*a/g<<'\n';
            else cout<<'\n';
        }else if(c==0){
            //x=0 or ax+b=0
            int g=gcd(b,a);
            if(newceil(-b,a)>0){
                if(a/g<0) a*=-1,b*=-1;
                cout<<-b/g;
                if(a/g!=1) cout<<'/'<<a/g<<'\n';
                else cout<<'\n';
            }
            else cout<<"0\n";
        }else cout<<"NO\n";
    }
    return 0;
}
