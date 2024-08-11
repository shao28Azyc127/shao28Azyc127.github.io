#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,m,a,b,c,q,p;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","r",stdout);
    scanf("%lld %lld",&t,&m);
    for(ll i=1;i<=t;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        if(b*b-4*a*c<0) cout<<"NO"<<endl;
        else if(b==0&&c==0)  cout<<0<<endl;
        else if(b*b==4*a*c) cout<<0<<endl;
        else{cout<<1<<endl;}
    }
    return 0;
}
