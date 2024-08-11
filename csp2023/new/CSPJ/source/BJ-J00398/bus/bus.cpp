#include<bits/stdc++.h>
using namespace std;
int pf(int x){
    for(int i=sqrt(x);i>=1;i--){
        if(x%(i*i)==0) return i;
    }
    return 1;
}
int gcd(int x,int y){
    if(x<0) x=-x;
    if(y<0) y=-y;
    if(y%x==0) return x;
    gcd(y%x,x);
}
int T,n,a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>n;
    while(T--){
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(d==0){
            if(2*a/gcd(b,2*d)==1||2*a/gcd(b,2*d)==-1)cout<<-b/gcd(b,2*a);
            else
            cout<<-b/gcd(b,2*a)<<"/"<<2*a/gcd(b,2*d);
            continue;
        }
        int x=pf(d);
        if(d==x*x){
            if(a>0){
                if((x-b)%2*a==0)
                cout<<(x-b)/gcd(x-b,2*a);
                else if(2*a/gcd(x-b,2*a)==1||2*a/gcd(x-b,2*a)==-1) cout<<(x-b)/gcd(x-b,2*a);
                else cout<<(x-b)/gcd(x-b,2*a)<<"/"<<2*a/gcd(x-b,2*a);
            } else{
                if((x-b)%2*a==0)
                cout<<(-x-b)/gcd(-x-b,2*a);
                else if(2*a/gcd(-x-b,2*a)==1||2*a/gcd(-x-b,2*a)==-1)cout<<(-x-b)/gcd(-x-b,2*a);
                else cout<<(-x-b)/gcd(-x-b,2*a)<<"/"<<2*a/gcd(-x-b,2*a);
            }
        }
        else if(a>0){
            if(b!=0){
                cout<<-(b/gcd(2*a,b))<<"/"<<2*a/gcd(2*a,b);
            }
            if(x==2*a) cout<<"+sqrt("<<d/x/x<<")";
            else if(x%(2*a)==0) cout<<"+"<<x/(2*a)<<"*sqrt("<<d/x/x<<")";
            else if((2*a)%x==0) cout<<"+"<<"sqrt("<<d/x/x<<")/"<<(2*a)/x;
            else cout<<"+"<<x/gcd(x,2*a)<<"*sqrt("<<d/x/x<<")/"<<2*a/gcd(x,2*a);
        }
        else{
            if(b!=0){
                cout<<-(b/gcd(2*a,b))<<"/"<<2*a/gcd(2*a,b);
            }
            if(x==2*a) cout<<"-sqrt("<<d/x/x<<")";
            else if(x%(2*a)==0) cout<<"-"<<x/(2*a)<<"*sqrt("<<d/x/x<<")";
            else if((2*a)%x==0) cout<<"-"<<"sqrt("<<d/x/x<<")/"<<(2*a)/x;
            else cout<<"-"<<x/gcd(x,2*a)<<"*sqrt("<<d/x/x<<")/"<<2*a/gcd(x,2*a);
        }
        cout<<endl;
    }
    return 0;
}
