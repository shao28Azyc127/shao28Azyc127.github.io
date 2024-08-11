#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
void you(long long p,long long q){
    if(p==0){
        cout<<"0\n";
        return;
    }
    long long nb=gcd(max(p,q),min(p,q));
    p=p/nb;
    q=q/nb;
    if(q<0){
        p=-p;
        q=-q;
    }
    if(q==1)cout<<p;
    else cout<<p<<"/"<<q;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long t,m,a,b,c;
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        long long n=b*b-4*a*c;
        if(n<0){
            cout<<"NO\n";
            continue;
        }
        long long ans=1;
        for(int b=2;b*b<=n;b++){
            while(n%(b*b)==0){
                ans=ans*b;
                n=n/b/b;
            }
        }
        if(n==0)ans=0;
        if(n==1 || n==0){
            long long p,q=2*a;
            if(a>0)p=ans-b;
            else p=-ans-b;
            you(p,q);
            cout<<"\n";
        }else{
            long long p=-b,q=2*a;
            if(b!=0){
                you(p,q);
                cout<<"+";
            }
            if(a<0)p=-ans;
            else p=ans;
            long long nb=gcd(max(p,q),min(p,q));
            p=p/nb;
            q=q/nb;
            if(q<0){
                p=-p;
                q=-q;
            }
            if(p==1 && q==1)cout<<"sqrt("<<n<<")";
            else if(q==1)cout<<p<<"*sqrt("<<n<<")";
            else if(p==1)cout<<"sqrt("<<n<<")/"<<q;
            else cout<<p<<"*sqrt("<<n<<")/"<<q;
            cout<<"\n";
        }
    }
    return 0;
}
