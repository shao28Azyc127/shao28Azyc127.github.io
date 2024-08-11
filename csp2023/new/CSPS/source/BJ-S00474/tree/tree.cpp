# include <bits/stdc++.h>
# define N 1000005
using namespace std;
__int128 lim=2000000000000000001ll;
int n;
vector<int> G[N];
long long a[N],b[N],c[N],l[N];
long long t[N];
bool ok(int id,__int128 l,__int128 r)
{
    if(l>r)
        return 0;
    __int128 res=0;
    if(c[id]<0 && r>t[id])
    {

        if(l>t[id])
            res=r-l+1;
        else
            res=min((2*b[id]+(l+t[id])*c[id]),lim)*(t[id]-l+1)/2+r-t[id];
    }
    else
        res=min((2*b[id]+(l+r)*c[id]),lim)*(r-l+1)/2;
    return res>=a[id];
}
int p[N];
void dfs(int x,int fa)
{
    for(auto to:G[x])
        if(to!=fa)
        {
            dfs(to,x);
            p[x]=min(p[x],p[to]-1);
        }
}
bool check(long long num)
{
    for(int i=1;i<=n;i++)
    {
        if(!ok(i,1,num))
            return 0;
        int L=1,R=min(n*1ll,num);
        while(L<=R)
        {
            int mid=L+R>>1;
            if(ok(i,mid,num))
            {
                p[i]=mid;
                L=mid+1;
            }
            else
                R=mid-1;
        }
    }
    dfs(1,0);
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
        if(p[i]<i)
            return 0;
    return 1;
}
long long maxl,minl=1100000000000000000ll;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        if(c[i]<0)
            t[i]=max((b[i]+(-c[i])-1)/(-c[i])-1,0ll);
        long long L=n,R=1000000000000000000ll+n;
        while(L<=R)
        {
            long long mid=L+R>>1;
            if(ok(i,n,mid))
                l[i]=mid,R=mid-1;
            else
                L=mid+1;
        }
        maxl=max(maxl,l[i]);
        minl=min(minl,l[i]);
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    long long L=minl,R=maxl,ans=R;
    while(L<=R)
    {
        long long mid=L+R>>1;
        if(check(mid))
        {
            ans=mid;
            R=mid-1;
        }
        else
            L=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
//-ulimit -s unlimited
//-fsanitize=undefined,address