#include<bits/stdc++.h>
#define ll long long
#define maxn 100001
using namespace std;
ll v[maxn];
ll a[maxn];
bool vis[maxn];
bool viss[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,d;
    cin>>n>>d;
    ll l=1e8;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<l){
            l=a[i];
            vis[i]=1;
        }
    }
    ll sum=0;
    ll now=0;
    ll ans=0;
    while(now!=n){

        int p=0;
        for(int i=now+1;i<=n;i++)
        {
            if(vis[i]==1){
                viss[i-1]=1;
                ans+=v[i-1];
                p=i;
                break;
            }
            else{
                ans+=v[i-1];
                viss[i-1]=1;
            }
        }
        if(p==0)p=n;
        if(ans%d==0)
        {
            sum+=(ans/d)*a[now];
            ans=0;
        }else{
            sum+=(ans/d+1)*a[now];
            ans-=(ans/d+1)*d;
        }
        now=p;
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
