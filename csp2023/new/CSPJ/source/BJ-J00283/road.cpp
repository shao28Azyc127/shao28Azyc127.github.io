#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int MAX=1e5+5;

int n,d,v[MAX],a[MAX];

int divideup(int a,int b)
{
    if(a%b==0)
    {
        return a/b;
    }
    else
    {
        return a/b+1;
    }
}

struct my
{
    int m;
    int y;
};
my dp[MAX];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i =1;i<=n-1;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=2;i<=n;i++)
    {
        dp[i].m=1e9+5;
        int l=0;
        for(int j=i-1;j>=1;j--)
        {
            l+=v[j];
            int money=dp[j].m+divideup(l-dp[j].y,d)*a[j];
            int yu=d*divideup(l-dp[j].y,d)-l+dp[j].y;
            if(dp[i].m>money)
            {
                dp[i].m=money;
                dp[i].y=yu;
            }
            else if(dp[i].m==money)
            {
                dp[i].y=max(dp[i].y,yu);
            }
        }
    }
    printf("%d",dp[n].m);
    return 0;
}

