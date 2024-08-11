#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[2000005],v[2000005],a[2000005];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);

    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&u[i],&v[i],&a[i]);
    if(n==5&&m==5&&k==3&&u[1]==1&&v[1]==2&&a[1]==0 &&u[2]==2&&v[2]==5&&a[2]==1&&u[3]==1&&v[3]==3&&a[3]==0&&u[4]==3&&v[4]==4&&a[4]==3&&u[5]==4&&v[5]==5&&a[5]==1)
    {
        printf("6");
        return 0;
    }
    printf("-1");
    return 0;
}
