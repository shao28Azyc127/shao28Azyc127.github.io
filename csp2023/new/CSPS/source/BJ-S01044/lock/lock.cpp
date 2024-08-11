#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][5];
int cnt,b[1005][5],ans;
int mp[1000005];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
            for(int k=1;k<=81;k++)
            {
                b[(i-1)*81+k][j]=a[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<5;j++)
        {
            for(int k=1;k<=9;k++)
            {
                int x=(i-1)*81+j*9+k;
                b[x][j]=(b[x][j]+k)%10;
            }
        }
        for(int j=0;j<4;j++)
        {
            for(int k=1;k<=9;k++)
            {
                int x=(i-1)*81+j*9+k+45;
                b[x][j]=(b[x][j]+k)%10;
                b[x][j+1]=(b[x][j+1]+k)%10;
            }
        }
    }
    for(int i=1;i<=n*81;i++)
    {
        int hs=0;
        for(int j=0;j<5;j++)hs=hs*10+b[i][j];
        mp[hs]++;
        if(mp[hs]==n)ans++;
    }
    printf("%d",ans);
    return 0;
}
