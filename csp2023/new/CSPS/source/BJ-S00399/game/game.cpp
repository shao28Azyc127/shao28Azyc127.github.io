#include<iostream>
#include<unordered_map>
#include<ctime>
using namespace std;

const int MXN=8010,MXM=200010;
int a[MXM],f[MXN][MXN];
unordered_map<int,int> g[MXM];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;cin>>n;
    if(n<=8000)
    {
        string s;cin>>s;
        for(int i=0;i<s.length();i++) a[i+1]=s[i]-'a'+1;
        for(int i=1;i<n;i++) if(a[i]==a[i+1]) f[i][i+1]=1;
        for(int l=3;l<=n;l++)
        {
            for(int i=1;i+l-1<=n;i++)
            {
                int j=i+l-1;
                // cout<<i<<' '<<j<<endl;
                if(a[j]==a[i]) f[i][j]=max(f[i][j],f[i+1][j-1]);
                if(f[i][j]) continue;
                for(int k=i;k<j;k++)
                {
                    if(f[i][k]&&f[k+1][j]) {f[i][j]=1;break;}
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(f[i][j]) ans+=f[i][j];
                // cout<<f[i][j]<<' ';
            }
            // cout<<endl;
        }
        cout<<ans<<endl;
    }
    else
    {
        string s;cin>>s;int l=0;
        for(int i=0;i<s.length();i++) a[i+1]=s[i]-'a'+1;
        for(int i=1;i<n;i++) 
        {
            // cout<<i<<endl;
            if(a[i]==a[i+1]) g[i][i+1]=1;
        }int ttmp=n;
        for(l=3;l<=24;l++)
        {
            // goto end;
            // if(clock()/CLOCKS_PER_SEC>=0.1) break;
            for(int i=1;i+l-1<=n;i++)
            {
                int j=i+l-1;
                // cerr<<i<<' '<<j<<endl;
                if(a[j]==a[i]) g[i][j]=max(g[i][j],g[i+1][j-1]);
                if(g[i][j]) continue;
                for(int k=i;k<j;k++)
                {
                    if(g[i][k]&&g[k+1][j]) {g[i][j]=1;/*cout<<i<<' '<<j<<endl;*/break;}
                }
            }
        }
        // cout<<l<<' '<<n<<endl;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(j-i>l) break;
                /*if(i==150||j==150) *///cout<<i<<' '<<j<<' '<<g[i][j]<<endl;
                ans+=g[i][j];
                // cout<<f[i][j]<<' ';
                // cerr<<i<<endl;
            }
            // cerr<<l<<endl;
            // cout<<endl;
        }end:;
        // cout<<g[150][153]<<endl;
        cout<<ans<<endl;
    }
    return 0;
}