#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long t,m;
    cin>>t>>m;
    for(long long i=1;i<=t;i++)
    {
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        long long s=b*b-4*a*c;
        if(s<0)
        {
            printf("NO\n");
        }
        if(s==0)
        {
            long long ans=(0-b)/(2*a);
            printf("%lld\n",ans);
        }
        if(s>0)
        {
            long long sq=sqrt(s);
            long long ans1=(s-b)/(2*a);
            long long ans2=(0-s-b)/(2*a);
            printf("%lld\n",max(ans1,ans2));
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}