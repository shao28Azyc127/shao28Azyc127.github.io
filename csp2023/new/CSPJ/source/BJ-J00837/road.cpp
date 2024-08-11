#include<bits/stdc++.h>
using namespace std;
long long n,t,v[100005],a[100005];
long long ans=0,patrol=0,money,minn=INT_MAX;
bool vis[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>t;
    for(int i=2;i<=n;i++){
        cin>>v[i];
        patrol+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    if(a[1]==minn){
        cout<<(patrol/t+1)*a[1];
        return 0;
    }
    for(int i=1;i<=n;i++){
        int x=i+1,cnt=0;
        if(vis[x]!=1){
            int j=x;
            while(a[j]<a[i]){
                vis[j]=1;
                cnt+=v[j];
                j++;
            }
            money+=(cnt/t+1)*a[i];
        }
    }
    cout<<money-v[n];
    return 0;
}
