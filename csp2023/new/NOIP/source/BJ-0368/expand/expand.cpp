#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c,n,m,q,a[500010],b[500010];
bool f[110][7][7];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    if(c==1)
    {
        cin>>a[1]>>b[1];
        if(a[1]!=b[1])cout<<1;
        else cout<<0;
        while(q--)
        {
            int k1,k2;
            cin>>k1>>k2;
            for(int i=1;i<=k1;i++)
            {
                int x,y;
                cin>>x>>y;
                a[x]=y;
            }
            for(int i=1;i<=k2;i++)
            {
                int x,y;
                cin>>x>>y;
                b[x]=y;
            }
            if(a[1]!=b[1])cout<<1;
            else cout<<0;
        }
    }
    if(c==2)
    {
        cin>>a[1]>>a[2]>>b[1]>>b[2];
        if(a[1]==b[1]||a[2]==b[2])cout<<0;
        else cout<<1;
        while(q--)
        {
            int k1,k2;
            cin>>k1>>k2;
            for(int i=1;i<=k1;i++)
            {
                int x,y;
                cin>>x>>y;
                a[x]=y;
            }
            for(int i=1;i<=k2;i++)
            {
                int x,y;
                cin>>x>>y;
                b[x]=y;
            }
            if(a[1]==b[1]||a[2]==b[2])cout<<0;
            else cout<<1;
        }
    }
    if(c==3||c==4)
    {
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=m;i++)cin>>b[i];
        f[0][0][0]=1;
        bool ans=0;
        bool ff;
        if(a[1]<b[1])ff=0;
        else ff=1;
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=n;j++)
                for(int k=1;k<=m;k++)
                {
                    f[i][j][k]|=f[i-1][j-1][k-1];
                    f[i][j][k]|=f[i-1][j][k-1];
                    f[i][j][k]|=f[i-1][j-1][k];
                    f[i][j][k]|=f[i-1][j][k];
                    if(a[j]==b[k])f[i][j][k]=0;
                    if(ff==0&&a[j]>b[k])f[i][j][k]=0;
                    if(ff==1&&a[j]<b[k])f[i][j][k]=0;
                    if(i==100&&j==n&&k==m)ans|=f[i][j][k];
                }
        }
        cout<<ans;
        while(q--)
        {
            int k1,k2;
            cin>>k1>>k2;
            for(int i=1;i<=k1;i++)
            {
                int x,y;
                cin>>x>>y;
                a[x]=y;
            }
            for(int i=1;i<=k2;i++)
            {
                int x,y;
                cin>>x>>y;
                b[x]=y;
            }
            memset(f,0,sizeof(f));
            if(a[1]<b[1])ff=0;
            else ff=1;
            f[0][0][0]=1;
            ans=0;
            for(int i=1;i<=100;i++)
            {
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=m;k++)
                    {
                        f[i][j][k]|=f[i-1][j-1][k-1];
                        f[i][j][k]|=f[i-1][j][k-1];
                        f[i][j][k]|=f[i-1][j-1][k];
                        f[i][j][k]|=f[i-1][j][k];
                        if(a[j]==b[k])f[i][j][k]=0;
                        if(ff==0&&a[j]>b[k])f[i][j][k]=0;
                        if(ff==1&&a[j]<b[k])f[i][j][k]=0;
                        if(i==100&&j==n&&k==m)ans|=f[i][j][k];
                    }
            }
            cout<<ans;
        }
    }
    return 0;
}