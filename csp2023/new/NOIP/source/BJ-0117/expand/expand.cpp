#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;
int st[500010][40],st2[500010][40];
int c,n,m,q;
int now;
int a[500010],b[500010];
int ta[500010],tb[500010];
int mi(int l,int r)
{
    int k=log2(r-l+1)/log2(2);
    return min(st[l][k],st[r+1-(1<<k)][k]);
}
int ma(int l,int r)
{
    int k=log2(r-l+1)/log2(2);
    return max(st2[l][k],st2[r+1-(1<<k)][k]);
}
int main()
{
    int i,j,k;
    bool dp[2010][2010];
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(j=1;j<=m;j++)
        scanf("%d",&b[j]);
    for(i=0;i<=q;i++)
    {
        for(j=1;j<=n;j++)
            ta[j]=a[j];
        for(j=1;j<=m;j++)
            tb[j]=b[j];
        if(i>0)
        {
            int kx,ky;
            scanf("%d%d",&kx,&ky);
            int p,v;
            for(j=1;j<=kx;j++)
            {
                scanf("%d%d",&p,&v);
                ta[p]=v;
            }
            for(j=1;j<=ky;j++)
            {
                scanf("%d%d",&p,&v);
                tb[p]=v;
            }
        }
        if(n<=2000&&m<=2000)
        {
            for(j=0;j<=n;j++)
                for(k=0;k<=m;k++)
                    dp[j][k]=0;
            dp[0][0]=true;
            if(ta[1]>tb[1])
            {
                for(j=1;j<=n;j++)
                    for(k=1;k<=m;k++)
                    {
                        if(ta[j]>tb[k])
                            dp[j][k]=dp[j][k-1]|dp[j-1][k]|dp[j-1][k-1];
                        else
                            dp[j][k]=0;
                    }
                cout<<dp[n][m];
            }
            else
            {
                for(j=1;j<=m;j++)
                    for(k=1;k<=n;k++)
                    {
                        if(tb[j]>ta[k])
                            dp[j][k]=dp[j][k-1]|dp[j-1][k]|dp[j-1][k-1];
                        else
                            dp[j][k]=0;
                    }
                cout<<dp[m][n];
            }
            continue;
        }
        if(ta[1]>tb[1])
        {
            for(j=0;j<=m;j++)
                st[j][0]=tb[j];
            for(j=1;(1<<j)<=m+1;j++)
                for(k=0;k+(1<<j)-1<=m+1;k++)
                    st[k][j]=min(st[k][j-1],st[k+(1<<(j-1))][j-1]);
            for(j=0;j<=m;j++)
                st2[j][0]=tb[j];
            for(j=1;(1<<j)<=m+1;j++)
                for(k=0;k+(1<<j)-1<=m+1;k++)
                    st2[k][j]=max(st2[k][j-1],st2[k+(1<<(j-1))][j-1]);
            now=0;
            bool fl=true;
            for(j=1;j<=n;j++)
            {
                if(ta[j]<=tb[min(now+1,m)])
                {
                    int l=0,r=now;
                    while(r>l)
                    {
                        int mid=(l+r+1)>>1;
                        if(mi(mid,r)<ta[j])
                            l=mid;
                        else
                            r=mid-1;
                    }
                    now=r;
                    if(now==0)
                    {
                        fl=false;
                        break;
                    }
                }
                else
                {
                    int l=now,r=m;
                    while(r>l)
                    {
                        int mid=(l+r+1)>>1;
                        if(mi(mid,r)<ta[j]&&ma(now,mid-1)<ta[j])
                            l=mid;
                        else
                            r=mid-1;
                    }
                    now=l;
                    if(now==0)
                    {
                        fl=false;
                        break;
                    }
                }
                //cout<<now<<" ";
            }
            //for(i=1;i<=n;i++)
                //cout<<ta[i]<<" ";
            //for(i=1;i<=m;i++)
                //cout<<tb[i]<<" ";
            //cout<<endl;
            if(fl&&now==m&&ta[n]>tb[m])
                cout<<1;
            else
                cout<<0;
        }
        else if(ta[1]==tb[1])
            cout<<0;
        else
        {
            for(j=0;j<=n;j++)
                st[j][0]=ta[j];
            for(j=1;(1<<j)<=n+1;j++)
                for(k=0;k+(1<<j)-1<=n+1;k++)
                    st[k][j]=min(st[k][j-1],st[k+(1<<(j-1))][j-1]);
            for(j=0;j<=n;j++)
                st2[j][0]=ta[j];
            for(j=1;(1<<j)<=n+1;j++)
                for(k=0;k+(1<<j)-1<=n+1;k++)
                    st2[k][j]=max(st2[k][j-1],st2[k+(1<<(j-1))][j-1]);
            now=0;
            bool fl=true;
            for(j=1;j<=m;j++)
            {
                if(tb[j]<=ta[min(now+1,n)])
                {
                    int l=0,r=now;
                    while(r>l)
                    {
                        int mid=(l+r+1)>>1;
                        if(mi(mid,r)<tb[j])
                            l=mid;
                        else
                            r=mid-1;
                    }
                    now=r;
                    if(now==0)
                    {
                        fl=false;
                        break;
                    }
                }
                else
                {
                    int l=now,r=n;
                    while(r>l)
                    {
                        int mid=(l+r+1)>>1;
                        if(mi(mid,r)<tb[j]&&ma(now,mid-1)<tb[j])
                            l=mid;
                        else
                            r=mid-1;
                    }
                    now=l;
                    if(now==0)
                    {
                        fl=false;
                        break;
                    }
                }
                //cout<<now<<" ";
            }
            //cout<<endl;
            if(fl&&now==n&&tb[m]>ta[n])
                cout<<1;
            else
                cout<<0;
        }
    }
    return 0;
}