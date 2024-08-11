#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e5+5;
int jl[maxn];
int jg[maxn];
bool vis[maxn];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    long long you=0;
    int i,j;
    for(i=1;i<n;i++)
    {
        cin>>jl[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>jg[i];
    }
    long long ans=0;
    for(i=1;i<=n;i++)
    {
        int jll=jl[i];
        if(vis[i]==1)
        {
            continue;
        }
        for(j=i+1;j<n;j++)
        {
            if(jg[j]>=jg[i])
            {
                jll+=jl[j];
                vis[j]=1;
            }
            else
            {
                break;
            }
        }
        jll-=you;
        jll=max(jll,0);
        ans+=jg[i]*(jll%d==0?jll/d:jll/d+1);
        you+=(jll%d==0?jll/d:jll/d+1)*d;
        you-=jll;
    }
    cout<<ans;
    return 0;
}

