#include<bits/stdc++.h>
using namespace std;
const int N=8e3+10;
int n,ans,a[N]; char x;
bool f[N][N];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n); getchar();
    for(int i=1;i<=n;i++)
    {
        x=getchar();
        a[i]=int(x-'a');
    }
    for(int l=2;l<=n;l++)
    {
        for(int x=1,y;x<=n-l+1;x++)
        {
            y=x+l-1;
            if(a[x]==a[y] && (l==2 || f[x+1][y-1])) f[x][y]=1;
            for(int k=x;k<y;k++) f[x][y]|=f[x][k]&f[k+1][y];
        }
    }
    for(int l=2;l<=n;l++)
        for(int x=1,y;x<=n-l+1;x++)
        {
            y=x+l-1;
            ans+=f[x][y];
        }
    printf("%d\n",ans);
    return 0;
}
