#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=1e5+10;
int s[10][6],tmp[6],dt[6];
bool check(int num)
{
    int i,cnt=0;
    for(i=1;i<=5;i++) dt[i]=0;
    for(i=1;i<=5;i++)
    {
        dt[i]=s[num][i]-tmp[i];
        if(dt[i]<0) dt[i]+=10;
    }
    for(i=1;i<=5;i++) if(dt[i]) cnt++;
    if(!cnt || cnt>=3) return false;
    if(cnt==1) return true;
    if(cnt==2)
    {
        int d1=0,d2=0,p1=0,p2=0;
        for(i=1;i<=5;i++)
        {
            if(dt[i])
            {
                if(!d1) d1=dt[i],p1=i;
                else d2=dt[i],p2=i;
            }
        }
        if(p2==p1+1)
        {
            if(d1==d2) return true;
        }
    }
    return false;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,m,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=5;j++) scanf("%d",&s[i][j]);
    }
    int res=0;
    for(i=0;i<=99999;i++)
    {
        tmp[1]=i/10000;
        tmp[2]=(i/1000)%10;
        tmp[3]=(i/100)%10;
        tmp[4]=(i/10)%10;
        tmp[5]=i%10;
        for(j=1;j<=n;j++)
        {
            if(!check(j)) break;
        }
        if(j>n) res++;
    }
    printf("%d",res);
    return 0;
}
