#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long T,m,a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&T,&m);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(b!=0 || c!=0)
        {
            printf("NO\n");
            continue;
        }
        if(a==1)
        {
            printf("-1\n");
            continue;
        }
        if(a==-1)
        {
            printf("1\n");
            continue;
        }
        printf("0\n");
    }
    return 0;
}
