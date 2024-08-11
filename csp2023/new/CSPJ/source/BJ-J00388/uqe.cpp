#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int t,m,a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    for(int i=0; i<t; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        int d=b*b-4*a*c;
        if(d<0)
        {
            printf("NO\n");
            continue;
        }
        printf("%d\n",(-b+sqrt(d))/(2*a));
    }
    return 0;
}
