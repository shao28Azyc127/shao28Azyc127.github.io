# include <bits/stdc++.h>
# define N 100005
using namespace std;
int n,m,k,d;
long long f[N];
int x[N],y[N],v[N];
vector<int> P[N];
struct Segment_Tree
{
    long long maxa[N<<2],tag[N<<2];
    void addtag(int now,long long x)
    {
        maxa[now]+=x;
        tag[now]+=x;
    }
    void pushdown(int now)
    {
        if(tag[now])
        {
            addtag(now<<1,tag[now]);
            addtag(now<<1|1,tag[now]);
            tag[now]=0;
        }
    }
    void update(int now,int l,int r,int x,long long y)
    {
        if(l==r)
        {
            maxa[now]=y;
            return ;
        }
        int mid=l+r>>1;
        if(x<=mid)
            update(now<<1,l,mid,x,y);
        else
            update(now<<1|1,mid+1,r,x,y);
        maxa[now]=max(maxa[now<<1],maxa[now<<1|1]);
    }
    void change(int now,int l,int r,int L,int R,long long x)
    {
        if(l>R || r<L)
            return ;
        if(L<=l && r<=R)
        {
            addtag(now,x);
            return ;
        }
        pushdown(now);
        int mid=l+r>>1;
        change(now<<1,l,mid,L,R,x);
        change(now<<1|1,mid+1,r,L,R,x);
        maxa[now]=max(maxa[now<<1],maxa[now<<1|1]);
    }
    long long get(int now,int l,int r,int L,int R)
    {
        if(l>R || r<L)
            return -1e18;
        if(L<=l && r<=R)
            return maxa[now];
        pushdown(now);
        int mid=l+r>>1;
        return max(get(now<<1,l,mid,L,R),get(now<<1|1,mid+1,r,L,R));
    }
}T;
void solve(int c)
{
    scanf("%d%d%d%d",&n,&m,&k,&d);
    if(c<=14)
    {
        memset(T.maxa,0,sizeof T.maxa);
        memset(T.tag,0,sizeof T.tag);
        for(int i=1;i<=n;i++)
            P[i].clear();
        for(int i=1;i<=m;i++)
        {
            int xx,yy;
            scanf("%d%d%d",&xx,&yy,&v[i]);
            x[i]=xx-yy+1;
            y[i]=xx;
            P[y[i]].push_back(i);
        }
        long long nowsum=0;
        for(int i=1;i<=n+1;i++)
        {
            f[i]=T.get(1,1,n,max(1,i-k-1),i-1)+d;
            if(i<=k+1)
                f[i]=max(f[i],nowsum+d);
            if(i!=n+1)
            {
                for(auto id:P[i])
                {
                    nowsum+=v[id];
                    T.change(1,1,n,1,x[id]-1,v[id]);
                }
                T.update(1,1,n,i,f[i]);
            }
        }
        printf("%lld\n",f[n+1]-1ll*(n+1)*d);
    }
    else if(c>=17 && c<=18)
    {
        memset(T.maxa,0,sizeof T.maxa);
        memset(T.tag,0,sizeof T.tag);
        f[0]=0;
        for(int i=1;i<=m;i++)
        {
            int xx,yy;
            scanf("%d%d%d",&xx,&yy,&v[i]);
            x[i]=xx-yy+1;
            y[i]=xx;
            f[0]+=1ll*(x[i]-y[i-1]-1)*d;
            f[0]+=v[i];
        }
        f[0]+=1ll*(n-y[m])*d;
        T.update(1,0,m,0,f[0]);
        v[m+1]=0;
        int pos=0,nowpos=0;
        for(int i=1;i<=m+1;i++)
        {
            while(y[i-1]-x[nowpos+1]+1>k && nowpos!=i-1)
                nowpos++,pos=nowpos;
            f[i]=T.get(1,0,m,pos,i-1)+1ll*(y[i]-x[i]+1)*d-v[i];
            if(i!=m+1)
                T.update(1,0,m,i,f[i]);
            if(i!=1 && x[i]!=y[i-1]+1)
                nowpos=i;
        }
        printf("%lld\n",f[m+1]-1ll*(n+1)*d);
    }
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
        solve(c);
    return 0;
}