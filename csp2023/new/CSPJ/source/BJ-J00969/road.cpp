#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,d,v[N],a[N],total=INT_MAX;
void dfs(long long x,long long price,long long cnt){
    if(x==n){
        total=price;
        return ;
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]<a[x]||i==n){
            long long ans=0;
            ans=v[i-1]-v[x-1];
            long long cnt1=(ans-cnt)/d;
            if(cnt1*d!=ans-cnt) cnt1++;
            price=price+cnt1*a[x];
            cnt=cnt+cnt1*d-ans;
            if(price>=total) return ;
            dfs(i,price,cnt);
            price=price-cnt1*a[x];
            cnt=cnt-cnt1*d+ans;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        v[i]=v[i]+v[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<total;
    return 0;
}