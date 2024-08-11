#include <bits/stdc++.h>

using namespace std;
long long n,p[10005][10005],a[10005],b[10005],c[10005],vis[10005],ans=2147483647,d[10005];
void aaa(long long dep,long long k,long long cnt)
{
    long long x=1;
    if(cnt==n)
    {

        //cout<<"a";
        int flag=1,mark=1;
        for(int i=1;i<=n;i++)
        {
            if(d[i]<a[i])
                flag=0;

            if(c[i]<0&&max(b[i]+dep*c[i],x)<a[i])mark=0;
        }
        if(flag==1)
        {
            ans=min(ans,dep-1);
            return;
        }
        else if(flag==0)
        {
            for(int i=1;i<=n;i++)
            d[i]+=max(b[i]+dep*c[i],x);
            aaa(dep+1,k,cnt);
            for(int i=1;i<=n;i++)
            d[i]-=max(b[i]+dep*c[i],x);
        }
    }
    else
    {
        int flag=0;
        for(long long i=1;i<=n;i++)
        {
            if(p[k][i]==1&&vis[i]==0)
            {
                //cout<<i<<dep<<"b";
                vis[i]=1;
                d[i]+=max(b[i]+dep*c[i],x);
                aaa(dep+1,i,cnt+1);
                d[i]-=max(b[i]+dep*c[i],x);
                vis[i]=0;
                flag=1;
            }
        }
        if(flag==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(i!=k);
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(p[i][j]!=0&&vis[j]==0&&vis[i]==1)
                        {
                            //cout<<j<<dep<<"c";
                            vis[j]=1;
                            d[j]+=max(b[j]+dep*c[j],x);
                            aaa(dep+1,j,cnt+1);
                            d[j]-=max(b[j]+dep*c[j],x);
                            vis[j]=0;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        d[i]=b[i];
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        p[x][y]=1;
        p[y][x]=1;
    }
    vis[1]=1;
    aaa(1,1,1);
    cout << ans<< endl;
    return 0;
}
