#include <iostream>
using namespace std;
#define int long long
const int N=10;
int a[N][N];
int n;
int t[N],tt[N][N],ttt[N][N];
int ans;
signed main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int i,j,k;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
        for(j=1; j<=5; j++)
            scanf("%lld",&a[i][j]);
    for(i=0; i<=99999; i++)
    {
        int temp=i;
        for(j=1; j<=5; j++)
        {
            t[j]=temp%10;
            temp/=10;
        }
        for(j=1; j<=n; j++)
            for(k=1; k<=5; k++)
                tt[j][k]=(t[k]-a[j][k]+10)%10,ttt[j][k]=(a[j][k]-t[k]+10)%10;
        for(j=1; j<=n; j++)
        {
            int sum=0;
            for(k=1; k<=5; k++)
                if(tt[j][k]==0)
                    sum++;
            if(sum==4)
                continue;
            if(sum!=3)
                break;
            for(k=1; k<5; k++)
                if((tt[j][k]==tt[j][k+1] && tt[j][k]!=0 || ttt[j][k]==ttt[j][k+1] && ttt[j][k]!=0))
                    break;
            if(k==5)
                break;
        }
        if(j==n+1)
            ans++;
    }
    printf("%lld",ans);
    return 0;
}
