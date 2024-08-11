#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,f[maxn],g[maxn],ans;
char a[maxn];
void init()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
}
void DP()
{
    f[1]=0,g[1]=-1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j=g[j]-1)
        {
            if(a[j]==a[i])
            {
                g[i]=j;
                break;
            }
        }
        if(g[i]<=0) continue;
        f[i]=f[g[i]-1]+1;
    }
}
void output()
{
    for(int i=1;i<=n;i++) ans+=f[i];
    cout<<ans;
}
void test()
{
    cout<<"\n\n\n";
    for(int i=1;i<=n;i++)
    {
        printf("f[%d]=%d\n",i,f[i]);
        // printf("g[%d]=%d\n\n",i,g[i]);
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    init();
    DP();
    output();
    // test();
    return 0;
}