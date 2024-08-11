#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n,a[10][10],ans;
int t[10];

bool check(int x,int i)
{
    int res=0;
    for(int j=0;j<5;j++) t[j]=x%10,x/=10;
    for(int j=0;j<5;j++)
        if(t[j]!=a[i][j]) res++;
    if(res==1) return true;
    if(res>2||res==0) return false;
    for(int j=0;j<4;j++)
        if(t[j]!=a[i][j]&&(t[j]-a[i][j]+10)%10==(t[j+1]-a[i][j+1]+10)%10)
        {
            return true;
        }
    return false;
}

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
        }
    }
    for(int x=0;x<100000;x++)
    {
        bool res=true;
        for(int i=1;i<=n;i++)
        {
            res&=check(x,i);
        }
        ans+=res;
    }
    printf("%d",ans);

    return 0;
}
