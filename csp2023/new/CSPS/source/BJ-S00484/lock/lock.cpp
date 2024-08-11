#include<bits/stdc++.h>
using namespace std;
const int N=15,K=5;
int n;
struct nd
{
    int a[N];
    void chan1(int x,int y)
    {
        a[x]=(a[x]+y)%10;
    }
    void chan2(int x,int y)
    {
        a[x]=(a[x]+y)%10;
        a[x%5+1]=(a[x%5+1]+y)%10;
    }
}a[N];
int ans;
bool chk(nd now,int x)
{
    for(int i=1;i<=K;i++) if(now.a[i]!=a[x].a[i]) return false;
    return true;
}
int can[N];
bool check(nd now)
{
    memset(can,0,sizeof(can));
    nd x=now;
    for(int i=1;i<=K;i++)
        for(int j=1;j<10;j++)
        {
            x.chan1(i,j);
            for(int k=1;k<=n;k++) if(chk(x,k)) can[k]=1;
            x=now;
        }
    for(int i=1;i<K;i++)
        for(int j=1;j<10;j++)
        {
            x.chan2(i,j);
            for(int k=1;k<=n;k++) if(chk(x,k)) can[k]=1;
            x=now;
        }
    for(int i=1;i<=n;i++) if(!can[i]) return false;
    return true;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=K;j++) scanf("%d",&a[i].a[j]);
    for(int x1=0;x1<10;x1++)
        for(int x2=0;x2<10;x2++)
            for(int x3=0;x3<10;x3++)
                for(int x4=0;x4<10;x4++)
                    for(int x5=0;x5<10;x5++)
                        if(check((nd){{0,x1,x2,x3,x4,x5}})) ans++;//,printf("%d %d %d %d %d\n",x1,x2,x3,x4,x5);
    printf("%d\n",ans);
    return 0;
}
