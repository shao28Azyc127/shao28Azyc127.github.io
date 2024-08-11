#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n;
long long dp[100005];
long long a[100005],b[100005],c[100005];
vector<int> s[100005];
__int128 js(int now,__int128 s,__int128 e){
    __int128 ans=0;
    if(c[now]>0){
        __int128 v=b[now],u=c[now];
        ans=(v+u*s+v+u*e)*(e-s+1);
        ans/=2;
    }else if(c[now]==0){
        if(b[now]==0){
            ans=(e-s+1);
        }else{
            __int128 v=b[now];
            ans=(e-s+1)*v;
        }
    }else if(c[now]<0){
        __int128 f=b[now]/(-c[now]);
        if(b[now]%(-c[now])==0){
            f--;
        }
        if(f>s){
            if(f>e){
                f=e;
            }
            __int128 v=b[now],u=c[now];
            ans=(v+u*s+v+u*f)*(f-s+1);
            ans/=2;
            s=f+1;
        }
        ans+=(e-s+1);
    }
    return ans;
}
int qz(int now,int mid){
    int l=1,r=mid,ans=0;
    while(l<=r){
        int mmid=(l+r)/2;
        if(js(now,mmid,mid)>=a[now]){
            l=mmid+1;
            ans=mmid;
        }else{
            r=mmid-1;
        }
    }
    return ans;
}
void dfs(int now,int fa,int mid){
    dp[now]=qz(now,mid);
    int len=s[now].size();
    for(int i=0;i<len;i++){
        if(s[now][i]==fa) continue;
        dfs(s[now][i],now,mid);
        dp[now]=min(dp[now],dp[s[now][i]]-1);
    }
}
bool check(int mid){
    dfs(1,0,mid);
    if(dp[1]>0) return true;
    return false;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        s[x].push_back(y);
        s[y].push_back(x);
    }
    int l=n,r=1e9,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    printf("%d",ans);
    return 0;
}
