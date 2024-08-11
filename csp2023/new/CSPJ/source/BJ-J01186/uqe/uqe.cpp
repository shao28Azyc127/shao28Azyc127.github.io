#include <bits/stdc++.h>
using namespace std;
int t,m;
int a,b,c,x1,x2;
int d,r;
void solve(){
    r=1;
    int tmp=sqrt(c);
    if(tmp*tmp==c) {cout<<tmp<<endl;}
    else{
        for(int i=2;i*i<=c;i++){
            while(c%(i*i)==0) {
                r*=i;
                c/=(i*i);
            }
        }
        if(r==1)    cout<<"sqrt("<<c<<")"<<endl;
        else cout<<r<<"*"<<"sqrt("<<c<<")"<<endl;
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(c==0)  {
            b=abs(b);
            cout<<max(b,0)<<endl;
            continue;
        }
        if(b==0) {
            if(c>0) cout<<"NO"<<endl;
            else{
                c=abs(c);
                solve();
            }
        }
        else{
            d=b*b-4*a*c;
            if(d<0) cout<<"NO"<<endl;
            else{
                b=0-b;
                x1=(b+sqrt(d))/(2*a);
                x2=(b-sqrt(d))/(2*a);
                cout<<max(x1,x2)<<endl;
            }
        }
    }
    return 0;
}
