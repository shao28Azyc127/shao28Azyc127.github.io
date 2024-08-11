#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,w;
}a[10005];
int f[10005],num[1005],s[1005];
vector<int >v[2005];
int main()
{
    int c,t;
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,m,k,d;
        memset(num,0,sizeof(num));
        memset(f,0,sizeof(f));
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>a[i].y>>x>>a[i].w;
            a[i].x=a[i].y-x+1;
            if(a[i].x<=0) continue;
            v[a[i].y].push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                num[a[v[i][j]].x]+=a[v[i][j]].w;
            }
            for(int j=1;j<=i;j++) s[j]=s[j-1]+num[j];
         //   cout<<endl;

            for(int j=i-k+1;j<=i;j++)
            {
                f[i]=max(f[i],f[j-1]+s[i]-s[j-1]-(i-j+1)*d);
              //  cout<<j<<" "<<f[j]+s[i]-s[j-1]-(i-j+1)*d<<" "<<j<<" "<<s[i]<<" "<<s[j-1]<<endl;
               // cout<<f[i]<<endl;
            }
            memset(s,0,sizeof(s));
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,f[i]);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                v[i][j]=0;
            }
        }
    }
    return 0;
}
