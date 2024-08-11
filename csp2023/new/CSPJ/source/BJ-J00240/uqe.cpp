#include<bits/stdc++.h>
using namespace std;
int t,m;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int dt=b*b-4*a*c;
        if(dt<0)
        {
            printf("NO\n");
            continue;
        }
        int ans=(sqrt(dt)-b)/2*a;
        printf("%d\n",ans);
    }
    return 0;
}
