//I'm a share bee, so what should I do?
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int n,a[15][15],num[15],cnt[100005],ans;

void check()
{
    for(int i=1;i<=100005;i++)
        if(cnt[i] == n) ans++;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
        {
            scanf("%d",&a[i][j]);
            num[i] += a[i][j] * pow(10,5-j);
        }

    //for node i, to make an edge to it's able nodes.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
            for(int k=1;k<=9;k++)
            {//change node i's number j, plus k.
                int newnum = num[i] - a[i][j] * pow(10,5-j) + ((k + a[i][j]) % 10) * pow(10,5-j);
                //printf("%d %d %d %d\n",i,j,k,newnum);
                cnt[newnum]++;

            }
        for(int j=1;j<=4;j++)
            for(int k=1;k<=9;k++)
            {//change node i's number j, plus k.
                int newnum = num[i] - a[i][j] * pow(10,5-j) - a[i][j+1] * pow(10,5-j-1) + ((k + a[i][j]) % 10) * pow(10,5-j) + ((k + a[i][j+1]) % 10) * pow(10,5-j-1);
                //printf("%d %d %d %d\n",i,j,k,newnum);
                cnt[newnum]++;
            }
    }

    check();
    printf("%d",ans);
    return 0;
}
