#include<iostream>
#include<cstdio>
using namespace std;
int n;
char c[2000010];
namespace S35
{
    bool f[810][810];
    void solve()
    {
        int ans=0;
        for(int i=1;i<n;i++)
            if(c[i]==c[i+1])
                f[i][i+1]=1,ans++;
        for(int len=4;len<=n;len+=2)
            for(int l=1;l+len-1<=n;l++)
            {
                int r=l+len-1;
                if(c[l]==c[r]&&f[l+1][r-1])
                    f[l][r]=1;
                for(int k=l+2;k<r;k+=2)
                    if(f[l][k-1]&&f[k][r])
                        f[l][r]=1;
                ans+=f[l][r];
            }
        cout<<ans<<endl;
    }
}
namespace SA{
    bool f[100010][15];
    void solve()
    {
        int ans=0;
        for(int i=1;i<n;i++)
            if(c[i]==c[i+1])
                f[i][2]=1,ans++;
        for(int len=4;len<=12;len+=2)
            for(int l=1;l+len-1<=n;l++)
            {
                int r=l+len-1;
                if(c[l]==c[r]&&f[l+1][len-2])
                    f[l][len]=1;
                for(int k=l+2;k<r;k+=2)
                    if(f[l][k-l]&&f[k][r-k+1])
                        f[l][len]=1;
                ans+=f[l][len];
            }
        cout<<ans<<endl;
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=800)S35::solve();
    else SA::solve();
    return 0;
}