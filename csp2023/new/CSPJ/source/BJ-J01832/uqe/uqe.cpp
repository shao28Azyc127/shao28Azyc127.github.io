#include <bits/stdc++.h>

using namespace std;

int t,m;
int a,b,c;

long long gcd(long long a,long long b){
    return a%b==0?b:gcd(b,a%b);
}
long long gh(long long a){
    long long maxn=0;
    for(long long i=2;i<=sqrt(a);i++){
        if(a%(i*i)==0)maxn=i;
    }
    return maxn;
}

void print(long long p,long long q){
    if(p==0){cout<<0;return;}
    if(q<0){q=-q,p=-p;}
    long long absp=abs(p);
    long long gcdpq=gcd(max(absp,q),min(absp,q));
    p/=gcdpq,q/=gcdpq;
    if(q==1){cout<<p;return;}
    cout<<p<<"/"<<q;
}

void go(){

    long long tg=b*b-4*a*c;
    if(tg<0){cout<<"NO"<<endl;return;}
    long long sqrttg=sqrt(tg);

    if(sqrttg*sqrttg==tg){
        long long p=a>0?-b+sqrttg:-b-sqrttg;
        long long q=2*a;
        print(p,q);
        cout<<endl;
        return;
    }
    else{
        long long q=a*2;
        if(b!=0&&q!=0){print(-b,q);cout<<"+";}
        q=abs(q);
        long long p=gh(tg);
        if(p){
            tg=tg/(p*p);
            long long gcdpq=gcd(max(p,q),min(p,q));
            p/=gcdpq,q/=gcdpq;
        if(p>1)cout<<p<<"*";
        }
        cout<<"sqrt("<<tg<<")";
        if(q>1)cout<<"/"<<q;
        cout<<endl;
        return;
    }
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        go();
    }

    return 0;
}
