#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+10;
int n;
vector<int> edge[maxn];
int a[maxn],b[maxn],c[maxn];
int f[maxn];
int stat[maxn];
int ans=1e15;
int calc(int i,int st,int n)
{
    if(c[i]==0) return b[i]*n;
    int t=b[i]/(-c[i]);
    if(c[i]>=0||(c[i]<0&&st<=-t))
    {
        return b[i]*n+(st+st+n-1)*c[i]*n/2;
    }
    else return b[i]*(-t)+(st+st+(-t)-1)*c[i]*(-t)/2+n+t;
}
int sol(int i,int aim,int st)
{
    int l=0,r=1e9,ans=0;
    if(aim<0) return 0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(calc(i,st,mid)>=aim)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
void dfs(int p)
{
    if(p>n)
    {

        int mx=0;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,sol(i,a[i]-f[i],p));
        }
        ans=min(ans,mx+p-1);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(stat[i]) continue;
        bool flag=0;
        for(int j=0;j<edge[i].size();j++)
        {
            int v=edge[i][j];
            if(stat[v])
            {
                flag=1;
                break;
            }
        }
        if(!flag) continue;
        stat[i]=p;
        for(int j=1;j<=n;j++)
        {
            if(!stat[j]) continue;
            f[j]+=max(p*c[j]+b[j],1ll);
        }
        dfs(p+1);
        stat[i]=0;
        for(int j=1;j<=n;j++)
        {
            if(!stat[j]) continue;
            f[j]-=max(p*c[j]+b[j],1ll);
        }
        f[i]=0;
    }
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    if(n<=20)
    {
        f[1]=max(b[1]+c[1],1ll);
        stat[1]=1;
        dfs(2);
        cout<<ans<<endl;
        return 0;
    }
    bool flag=0;
    for(int i=2;i<n;i++)
    {
        if(edge[i].size()!=2)
        {
            flag=1;
            break;
        }
        if(edge[i][0]==i-1&&edge[i][1]==i+1) continue;
        if(edge[i][1]==i-1&&edge[i][0]==i+1) continue;
        flag=1;
        break;
    }
    if(!flag)
    {
        for(int i=1;i<=n;i++)
        {
            f[i]=calc(i,i,n-i+1);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,sol(i,a[i]-f[i],n+1));
        }
        cout<<ans+n<<endl;
        return 0;
    }
	return 0;
}
