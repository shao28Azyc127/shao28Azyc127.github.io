#include<bits/stdc++.h>
using namespace std;
int n,a[11][11],ans=0;
int b[11];
inline bool check(int x)
{
    for(int i=5;i>=1;i--)
    {
        b[i]=x%10;
        x/=10;
    }
    for(int i=1;i<=n;i++)
    {
        int sum=0,A=0,B=0;
        for(int j=1;j<=5;j++)
        {
            if(b[j]==a[i][j]) continue;
            sum++;
            if(A==0) A=j;
            else B=j;
        }
        if(sum==0||sum>=3) return false;
        if(sum==1) continue;
        if(A+1!=B) return false;
        if((b[A]-a[i][A]+10)%10!=(b[B]-a[i][B]+10)%10) return false;
    }
    return true;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=0;i<=99999;i++)
        if(check(i)) ans++;
    printf("%d",ans);
    return 0;
}
