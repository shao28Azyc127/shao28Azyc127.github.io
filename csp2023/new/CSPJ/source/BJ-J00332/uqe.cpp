#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    scanf("%d%d",&T,&M);
    while(T--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(b==0&&c==0)
        {
            printf("0\n");
            continue;
        }
        long long temp=1ll*b*b-4ll*a*c;
        if(temp<0)printf("No\n");
        else
        {
            long long t1=sqrt(temp);
            if(t1*t1==temp)
            {
                long long t2=b*(-1ll)+t1;
                if(t2%2==0)
                {
                    printf("%lld\n",t2/2);
                    continue;
                }
            }
        }
    }
    return 0;
}