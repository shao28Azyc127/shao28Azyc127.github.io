#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
const long long N=1e5+12;
long long n;
long long a,b,c,u,v;
vector <long long> G[N];
struct Node
{
    long long a,b,c;
};
Node p[N];
typedef  pair<long long,long long> pii;
namespace A
{
    long long h[N];
    bool unlock[N];
    long long day=0;
    inline void calc_hight(long long day)
    {
        for(long long i=1;i<=n;i++)
        {
            if(unlock[i])
            h[i]+=p[i].b;
        }
    }
    inline void calc_hight_time(long long time)
    {
        for(long long i=1;i<=n;i++)
        {
            if(unlock[i])
            h[i]+=time*p[i].b;
        }
    }
    inline bool check()
    {
        for(long long i=1;i<=n;i++)
        {
            if(h[i]<p[i].a)
                return false;
        }
        return true;
    }
            bool check_time(long long ti)
        {
            for(long long i=1;i<=n;i++)
            {
                if(h[i]+p[i].b*ti<p[i].a)
                    return false;
            }
            return true;
        }
    priority_queue<pii, vector<pii>, greater<pii> > q;
    long long solve()
    {
        unlock[1]=true;
        q.push(make_pair(p[1].b,1));
        while(!q.empty())
        {
            pii u=q.top();
            q.pop();
            day++;
            calc_hight(day);
            for(long long v:G[u.second])
            {
                if(unlock[v])
                    continue;
                unlock[v]=true;
                q.push(make_pair(p[v].b,v));
            }
            if(check())
                return day;
        }


        //waiting

        long long tmpday=-1;
        for(long long i=1;i<=n;i++)
        {
            tmpday=max(tmpday,((p[i].a-h[i])/p[i].b));
        }
        tmpday+=1000;
        day+=tmpday;
        for(long long i=1;i<=n;i++)
        {
            h[i]+=tmpday*p[i].b;
        }
        while(check())
        {
            day--;
            for(long long i=1;i<=n;i++)
                h[i]-=p[i].b;
        }
        return day;

    }
}
namespace B
{
    long long day;
    bool unlock[N];
    long long h[N];
    inline void calc_hight(long long day)
    {
        for(long long i=1;i<=n;i++)
        {
            if(unlock[i])
            h[i]+=p[i].b+p[i].c*day;
        }
    }
    inline bool check()
    {
        for(long long i=1;i<=n;i++)
        {
            if(h[i]<p[i].a)
                return false;
        }
        return true;
    }


    long long solve()
    {
        for(long long i=1;i<n;i++)
        {
            day++;
            unlock[i]=true;
            calc_hight(day);
        }
        //waiting
        while(!check())
        {
            day++;
            calc_hight(day);
        }
        return day;
    }
}
bool stat_a()
{
    for(int i=1;i<=n;i++)
    {
        if(p[i].c!=0)
            return false;
    }
    return true;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        p[i].a=a,p[i].b=b,p[i].c=c;
    }
    for(long long i=1;i<=n-1;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(stat_a())
        cout<<A::solve();
    else
        cout<<B::solve();
    return 0;
}
/*
7

*/
