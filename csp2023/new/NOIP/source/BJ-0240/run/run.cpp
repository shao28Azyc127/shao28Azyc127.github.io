#include<bits/stdc++.h>
using namespace std;
long long x[100005],y[100005],v[100005];
bool vis[100005];
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    long long c,t,n,m,k,d,ans=0,l,r;
    cin>>c>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(v,0,sizeof(v));
        ans=0;
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
        {
            cin>>x[i]>>y[i]>>v[i];
            if(k<y[i]||x[i]<y[i])
                continue;
            if(x[i]-y[i]+1>x[i-1]+1)
            {
                if(y[i]*d<=v[i])
                {
                    ans=ans-y[i]*d+v[i];
                    vis[i]=true;
                }
            }
            /*else
            {
                l=y[i],r=v[i];
                for(int j=i-1;j>=1;j--)
                {
                    if(x[j]-y[j]+1>=x[i]-y[i]+1)
                    {
                        if(vis[j])
                            l-=y[j];
                        else
                            r+=v[j];
                    }
                    else if(x[j]+1<x[i]-y[j]+1)
                    {
                        if(l*d<=r)
                        {
                            ans=ans-l*d+v[i];
                            vis[i]=true;
                        }
                        break;
                    }
                    else
                    {
                        if(vis[j])
                        {
                            if(x[i]-x[j]-1+y[j]<=k)
                            {
                                l-=(x[j]-(x[i]-y[i]+1)+1);
                                if(l*d<=r)
                                {
                                    ans=ans-l*d+v[i];
                                    vis[i]=true;
                                }
                                break;
                            }
                            else
                            {

                            }
                        }
                        else
                        {
                            if(x[i]-x[j]-1+y[j]<=k&&)
                            {

                            }
                        }
                    }
                }
            }*/
        }
        cout<<ans<<endl;
    }
    return 0;
}
