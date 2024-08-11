#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int n,d,sum=0,t,p;
    freopen(road.in,'r',stdin);
    freopen(road.out,'w',stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1;i<n;i++)
    {
        scanf("%d",&t);
        sum+=t;
    }
    scanf("%d",&p);
    if(sum%d==0)
        printf("%d",(sum/d*p));
    else
        printf("%d",((sum/d+1)*p));
    return 0;
}
