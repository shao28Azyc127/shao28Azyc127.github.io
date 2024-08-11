#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,bz,tot,ans,ls=1,bef;
queue<ll>q;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i)q.push(i);
    while(!q.empty()){
        if(bef>=q.front()){
            bz=0;
            ls++;
        }
        bef=q.front();
        if(bz==3)bz=0;
        if(!bz){
            if(q.front()==n)ans=ls;
        }
        else q.push(q.front());
        q.pop();
        bz++;
    }
    printf("%lld %lld",ls,ans);
    return 0;
}
