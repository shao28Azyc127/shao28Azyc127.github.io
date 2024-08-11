#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> g[100007];
struct node{
    int x,id;
};
bool cmp(node x,node y){
    return x.x<y.x;
}
int a[100007],b[100007],c[100007],n,dep[100007],f[100007];
node t[100007];
int dis(int x,int y){
    int res=0;
    while(x!=y){
        if(dep[x]>dep[y]) x=f[x];
        else y=f[y],res++;
    }
    return res;
}
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    f[u]=fa;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v,u);
    }
}
bool check(int u){
    for(int i=1;i<=n;i++){
        bool flag=false;
        int sum=0;
        for(int j=u;j>=0;j--){
            sum+=max(j*c[i]+b[i],1);
            if(sum>=a[i]){
                t[i].x=j;
                flag=true;
                break;
            }
        }
        t[i].id=i;
        if(!flag) return false;
    }
    sort(t+1,t+1+n,cmp);
    int now=1,cur=1;
    for(int i=1;i<=n;i++){
        if(t[i].id==1) continue;
        //if(u<10){
        //    printf("%d %d %d\n",u,cur,now);
        //}
        int tmp=dis(cur,t[i].id);
        if(tmp+now>t[i].x) return false;
        now+=tmp;
        cur=t[i].id;
    }
    return true;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    int l=1,r=1000000,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}