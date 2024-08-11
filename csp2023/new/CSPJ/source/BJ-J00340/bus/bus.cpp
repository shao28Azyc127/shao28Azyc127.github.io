#include<iostream>
#include<cstdio>
using namespace std;
#define INF 99999999
int p[1000005][1000005],n,m,k,tm[1000005];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            p[i][j]=INF;
            if(i==j) p[i][j]=0;
        }
    }
    int maxa=0;
    for(int i=1;i<=m;i++)
    {
        int s,e,t;
        cin>>s>>e>>t;
        p[s][e]=1;
        tm[i]=t;
        if(t>maxa) maxa=t;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            for(int q=j+1;q<=n;q++)
            {
                if(j==1 and q==n)
                {
                    if(p[j][q]>p[j][i]+p[i][q] and (p[j][i]+p[i][q])%k==0)
                        p[j][q]=p[j][i]+p[i][q];
                }
                else
                {
                    if(p[j][q]>p[j][i]+p[i][q])
                        p[j][q]=p[j][i]+p[i][q];
                }
            }
        }
    }
    if(p[1][n]==INF) cout<<"-1";
    else
    {
        if(maxa%k==0) cout<<p[1][n]+maxa;
        else cout<<p[1][n]+(maxa%k+1)*k;
    }
    return 0;
}
