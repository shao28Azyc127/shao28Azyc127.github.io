#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
struct tr
{
    long long a;
    long long b;
    long long c;
};
struct lj
{
    int x;
    int y;
};
lj jl[10000];
long long g[10000];
bool ok[10000];
bool sf[10000];
int n;
int yz=0;
tr ee[10000];
int y=0;
int bj()
{
    int yr=0;
    bool fs=false;
    if(fs==false)
    {
        for(int i=0;i<n;i++)
        {
            if(sf[i])
            {
                yr+=1;
            }
        }
        yz=yr;
        if(yz==n)
        {
            fs=true;
        }
        int s;
        long long u=0;
        for(int j=0;j<n;j++)
        {
            if(sf[j])
            {
                for(int i=0;i<n;i++)
                {
                    long long p=ee[jl[i].y].a/ee[jl[i].y].b;
                    if(jl[i].x==j)
                    {
                        u=max(u,p);
                        if(p>u)
                        {
                            s=i;
                        }
                    }
                }
            }
        }
        y=s;
        return s;
    }
    if(fs)
    {
        return y;
    }

}
bool zw()
{
    for(int i=0;i<n;i++)
    {
        if(ok[i])
        {
            return true;
        }
    }
    return false;
}
void pd()
{
    for(int i=0;i<n;i++)
    {
        if(g[i]>=ee[i].a)
        {
            ok[i]=false;
        }
    }
}
void sz()
{
    for(int i=0;i<n;i++)
    {
        if(sf[i])
        {
            if(ee[i].b-1>0)
            {
                g[i]+=ee[i].b;
            }
            else
            {
                g[i]+=1;
            }
        }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ee[i].a>>ee[i].b>>ee[i].c;
        ok[i]=true;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>jl[i].x>>jl[i].y;
    }
    int ti=0;
    int sh=0;
    while(zw())
    {
        ti++;
        sf[sh]=true;
        sz();
        pd();
        sh=bj();
    }
    cout<<ti;
    return 0;
}
