#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
int gcd(int x,int y){
    int tmp;
    while(x%y!=0){
        x=x%y;
        tmp=x;
        x=y;
        y=tmp;
    }
    return y;
}
void print(int x,int y){
    int k=gcd(x,y);
    x/=k;
    y/=k;
    if(y<0) y*=-1,x*=-1;
    cout<<x;
    if(y!=1)cout<<"/"<<y;
}
void print(int d,int x,int y){
    int i=2;
    while(i*i<=x){
        while(x%(i*i)==0) d*=i,x/=i*i;
        i++;
    }
    int k=gcd(d,y);
    d/=k;
    y/=k;
    if(d!=1) cout<<d<<"*";
    cout<<"sqrt("<<x<<")";
    if(y!=1) cout<<"/"<<y;
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int delta=b*b-4*a*c;
    if(delta<0){
        cout<<"NO\n";
        return;
    }
    int d=sqrt(delta);
    if(d*d==delta){
        if(a>0) print(d-b,2*a);
        else print(-d-b,2*a);
    }
    else{
        if(b!=0) print(-b,2*a),cout<<"+";
        print(1,delta,abs(2*a));
    }
    cout<<endl;
    return;
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,n;
    cin>>t>>n;
    while(t--) solve();
    return 0;
}