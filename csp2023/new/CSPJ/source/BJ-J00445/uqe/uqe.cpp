#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

int t,m,a,b,c;

int gcd(int p,int q){
    if(p==0||q==0)return p==0?q:p;
    if(p<q)swap(p,q);
    return gcd(q,p%q);
}

int pfs(int n){
    for(int i=0;i*i<=n;i++)if(i*i==n)return i;
    return -1;
}

void yls(int p,int q){
    int pq=gcd(p,q);
    p/=pq,q/=pq;
    if(q<0)q=-q,p=-p;
    if(q==1)cout<<p;
    else cout<<p<<'/'<<q;
}

int gq2(int n){
    for(int i=100;i>1;i--)if(!(n%(i*i)))return i*i;
    return 0;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO\n";
            continue;
        }
        if(pfs(b*b-4*a*c)!=-1)yls(pfs(b*b-4*a*c)-b,2*a),cout<<'\n';
        else cout<<"qaq\n";
    }
    return 0;
}
