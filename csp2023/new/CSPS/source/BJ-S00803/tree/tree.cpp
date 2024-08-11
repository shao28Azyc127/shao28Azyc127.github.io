#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100001],b[100001],c[100001],k,ans;
bool aq,bq,dq,vis[114514];
vector<int>zyz[100001];
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        if(c[i]!=0)aq=1;
    }for(int i=1,u,v;i<n;i++){
        scanf("%lld%lld",&u,&v);
        if(u!=1)bq=1;
        zyz[u].push_back(v);
        zyz[v].push_back(u);
    }
    if(aq==0){
        vis[1]=1;
        if(a[1]%b[1]==0)ans=max(ans,a[1]/b[1]+1);
        else ans=max(ans,a[1]/b[1]+2);
        int l=zyz[1][0],r=zyz[1][0];
        for(int i=2,lday,rday;i<=n;i++){
            if(a[l]%b[l]==0)lday=a[l]/b[l];
            else lday=a[l]/b[l]+1;
            if(a[r]%b[r]==0)rday=a[r]/b[r];
            else rday=a[r]/b[r]+1;
            if(lday>rday){
                vis[l]=1;
                ans=max(ans,lday+i);
                if(zyz[l].size()==2){
                    if(vis[zyz[l][0]]==0)l=zyz[l][0];
                    else l=zyz[l][1];
                }
            }else{
                vis[r]=1;
                ans=max(ans,rday+i);
                if(zyz[r].size()==2){
                    if(vis[zyz[r][0]]==0)r=zyz[r][0];
                    else r=zyz[r][1];
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
