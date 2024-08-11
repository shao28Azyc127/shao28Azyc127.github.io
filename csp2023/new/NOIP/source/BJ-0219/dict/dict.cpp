#include<bits/stdc++.h>
using namespace std;
int vis[3005];
int c[3005];
int v[3005][30];
int ans[3005];
int main()
{
    int n,m;
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char s;
            cin>>s;
           // cout<<i<<" "<<s<<" "<<int(s)-96<<endl;
            v[i][int(s)-96]++;

        }
    }
    for(int i=26;i>=1;i--)
    {
        int minx=10000;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]) minx=min(minx,v[j][i]);
        }
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&v[j][i]!=minx) vis[j]=1;
        }
    }
    int maxnow;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            maxnow=i;
            break;
        }
    }
    int ansx;
    for(int i=26;i>=1;i--)
    {
        if(v[maxnow][i])
        {ansx=i;break;}
    }
    ans[maxnow]=1;
 //   cout<<maxnow<<endl;
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=26;i++)
        {
            if(j==maxnow) break;
            if(v[j][i])
            {
                c[j]=i;
               // cout<<j<<" "<<i<<" "<<v[j][i]<<endl;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i]>=ansx) ans[i]=0;
        else ans[i]=1;
      //  cout<<c[i]<<endl;
    }
    for(int i=1;i<=n;i++) cout<<ans[i];
    return 0;
}
