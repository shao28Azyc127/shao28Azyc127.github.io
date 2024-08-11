#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b){
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
void outdiv(int a,int b){
    if(a==0){
        cout<<0;
        return ;
    }
    int aa=abs(a),bb=abs(b);
    int g=gcd(aa,bb);
    if((a>0&&b>0)||(a<0&&b<0)) b=bb/g,a=aa/g;
    else b=bb/g,a=-aa/g;
    if(b==1) cout<<a;
    else cout<<a<<"/"<<b;
}
void outsq(int a,int b,int c,int d,int r){
    int aa=abs(c),bb=abs(d);
    int g=gcd(aa,bb);
    if((c>0&&d>0)||(c<0&&d<0)) d=bb/g,c=aa/g;
    else d=-bb/g,c=aa/g;
    if(a!=0) outdiv(a,b),cout<<"+";
    if(c!=1) cout<<c<<"*";
    cout<<"sqrt("<<r<<")";
    if(d!=1) cout<<"/"<<d;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M; cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0) cout<<"NO";
        else if(delta==0){
            outdiv(-b,2*a);
        }
        else{
            int t=1;
            for(int i=2;i*i<=delta;i++){
                if(delta%(i*i)==0) delta/=(i*i),t*=i;
            }
            if(delta==1){
                if(a>0) outdiv(t-b,2*a);
                else outdiv(-t-b,2*a);
            }
            else{
                if(a>0) outsq(-b,2*a,t,2*a,delta);
                else outsq(b,-2*a,t,-2*a,delta);
            }
        }
        cout<<endl;
    }
    return 0;
}
