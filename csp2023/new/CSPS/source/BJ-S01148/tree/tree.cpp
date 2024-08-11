#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a,b,sum=0,minn=LONG_LONG_MAX;
ll p[100010];
stack<ll> s[100010];
bool flag[100010];
struct node
{
    ll a,b,c;
} x[100010];
vector<ll> v[100010];
inline void f(int y)
{
    bool flaga=false;
    for(int i=1;i<=n;++i)
    {
        if(flag[i])
        {
            if(x[i].b+y*x[i].c>1)
            {
                s[i].push(s[i].top()+x[i].b+y*x[i].c);
            }
            else
            {
                s[i].push(s[i].top()+1);
            }
            if(s[i].top()<x[i].a)
            {
                flaga=true;
            }
        }
    }
    /*
    cout<<y<<" "<<k<<" "<<sum<<endl;
    for(int i=1;i<=n;++i)
    {
        if(!s[i].empty())
        {
            cout<<s[i].top()<<" ";
        }
        else
        {
            cout<<"  ";
        }
    }
    cout<<endl;
    */
    if(!flaga&&sum==n)
    {
        //cout<<"a"<<endl;
        if(y<minn)
        {
            minn=y;
        }
        for(int i=1;i<=n;++i)
        {
            if(!s[i].empty())
            {
                s[i].pop();
            }
            if(s[i].empty())
            {
                flag[i]=false;
                --sum;
            }
        }
        return;
    }
    else if(sum==n)
    {
        //cout<<"b"<<endl;
        f(y+1);
        for(int i=1;i<=n;++i)
        {
            if(!s[i].empty())
            {
                s[i].pop();
            }
            if(s[i].empty())
            {
                flag[i]=false;
                --sum;
            }
        }
        return;
    }
    //cout<<sum<<endl;
    for(int j=1;j<=sum;++j)
    {
        int l=v[p[j]].size();
        //cout<<p[j]<<" ";
        for(int i=0;i<l;++i)
        {
            if(!flag[v[p[j]][i]])
            {
                flag[v[p[j]][i]]=true;
                s[v[p[j]][i]].push(ll(0));
                p[++sum]=v[p[j]][i];
                //cout<<p[sum]<<" ";
                f(y+1);
            }
        }
    }
    //cout<<endl;
    //cout<<"c"<<endl;
    for(int i=1;i<=n;++i)
    {
        if(!s[i].empty())
        {
            s[i].pop();
        }
        if(s[i].empty())
        {
            flag[i]=false;
            --sum;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    m=n-1;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i].a>>x[i].b>>x[i].c;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    flag[1]=true;
    p[++sum]=1;
    s[1].push(0);
    f(1);
    cout<<minn;
    return 0;
}
