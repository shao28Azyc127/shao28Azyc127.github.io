#include<bits/stdc++.h>
using namespace std;
int n;
__int128 a[100005],b[100005],c[100005];
vector<int>v[100005];
int deep[100005],size[100005],hson[100005],top[100005],father[100005];
int deepest[100005];
struct node{
    int id,timee;
    bool operator<(const node &rhs)const
    {
        if(timee>rhs.timee)
        {
            return true;
        }
        return false;
    }
};
int cnt=0;
void insertt(int x)
{
    if(deepest[top[x]]!=0)
    {
        if(deep[deepest[top[x]]]>deep[x])
        {
            return;
        }
        cnt+=deep[x]-deep[deepest[top[x]]];
        deepest[top[x]]=x;
        return;
    }
    if(top[x]==1)
    {
        cnt+=deep[x];
        deepest[1]=x;
        return;
    }
    cnt+=deep[x]-deep[father[top[x]]];
    deepest[top[x]]=x;
    insertt(father[top[x]]);
}
void dfs1(int x,int fa)
{
    size[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i];
        if(fa==xx)
        {
            continue;
        }
        deep[xx]=deep[x]+1;
        father[xx]=x;
        dfs1(xx,x);
        if(size[hson[x]]<size[xx])
        {
            hson[x]=xx;
        }
        size[x]+=size[xx];
    }
}
void dfs2(int x,int fa)
{
    if(hson[x])
    {
        top[hson[x]]=top[x];
        dfs2(hson[x],x);
    }
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i];
        if(fa==xx||xx==hson[x])
        {
            continue;
        }
        top[xx]=xx;
        dfs2(xx,x);
    }
}
inline __int128 check1(int i,__int128 x)
{
    if(x==-1)
    {
        return 0;
    }
    if(b[i]+x*c[i]<=0)
    {
        __int128 now=(b[i]-1)/(-c[i]);
        //1~now  now+1~x
        //cout<<"??"<<i<<" "<<x<<(x-now)+now*b[i]+now*(now+1)/2*c[i]<<endl;
        return (x-now)+now*b[i]+now*(now+1)/2*c[i];
    }
    else
    {
        //cout<<"???"<<i<<" "<<x*b[i]+x*(x+1)/2*c[i]<<endl;
        return x*b[i]+x*(x+1)/2*c[i];
    }
}
int ef1(int key1,int day,int l,int r)
{
    if(l==r)
    {
        return l;
    }
    int mid=(l+r+1)>>1;
    if((check1(key1,day)-check1(key1,mid-1))>=a[key1])
    {
        return ef1(key1,day,mid,r);
    }
    else
    {
        return ef1(key1,day,l,mid-1);
    }
}
inline bool check2(int x)
{
    priority_queue<node>q;
    for(int i=1;i<=n;i++)
    {
        node tmp;
        tmp.id=i;
        tmp.timee=ef1(i,x,0,1e5);
        //cout<<"::"<<x<<" "<<" "<<tmp.id<<" "<<tmp.timee<<endl;
        if(tmp.timee==0)
        {
            return false;
        }
        q.push(tmp);
    }
    for(int i=1;i<=n;i++)
    {
        deepest[i]=0;
    }
    cnt=0;
    while(!q.empty())
    {
        insertt(q.top().id);
        if(cnt>q.top().timee)
        {
            return false;
        }
        q.pop();
    }
    return true;
}
void ef2(int l,int r)
{
    if(l==r)
    {
        cout<<l;
        exit(0);
    }
    int mid=(l+r)>>1;
    if(check2(mid))
    {
        return ef2(l,mid);
    }
    else
    {
        return ef2(mid+1,r);
    }
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    long long x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]=x;
        cin>>x;
        b[i]=x;
        cin>>x;
        c[i]=x;
    }
    int s,t;
    for(int i=1;i<n;i++)
    {
        cin>>s>>t;
        v[s].push_back(t);
        v[t].push_back(s);
    }
    deep[1]=1;
    dfs1(1,0);
    top[1]=1;
    dfs2(1,0);
    ef2(n,1e9);
    return 0;
}
