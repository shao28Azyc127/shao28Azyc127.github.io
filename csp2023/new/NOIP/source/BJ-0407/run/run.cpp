#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#define int long long
using namespace std;
int n,m,d,c,k,QAQ;
int dp[5005][5005];
struct chall
{
    int x,y,v;
} a[100005];
bool operator<(chall a,chall b)
{
    return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
void Main()
{
    memset(dp,0,sizeof(dp));
    memset(dp[0],0xc0,sizeof(dp[0]));
    dp[0][0]=0;
    cin>>n>>m>>k>>d;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].v;
        if(a[i].y>k)
        {
            a[i].x=a[i].y=a[i].v=0;
        }
    }
    sort(a+1,a+m+1);
    int pos=1,maxx=0;
    /*printf("   |");
    for(int i=1;i<=k;i++)
        printf("%3d ",i);
    printf("\n---+");
    for(int i=1;i<=k;i++)
        printf("----");*/
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=maxx;
        //printf("\n%3d|",i);
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j-1]-d;
            while(a[pos].y<=j&&a[pos].x<=i&&pos<=m)
            {
                maxx=max(maxx,dp[i][j]+=a[pos].v);
                //cout<<i<<' '<<j<<' '<<a[pos].y<<' '<<a[pos].x<<'#';
                pos++;
            }
            //cout<<pos<<' '<<a[pos].x<<' '<<a[pos].y;
            //printf("%3lld ",dp[i][j]);
        }
        //printf("\n");
    }
    cout<<maxx<<'\n';
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>QAQ;
    while(QAQ--) Main();
    return 0;
}
