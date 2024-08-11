#include<bits/stdc++.h>
using namespace std;
int n,a[100005],d,v[100005];
int main()
{
    freopen("rode.in","r",stdin);
    freopen("rode.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int sum=0,money=0;
    for(int i=0;i<n-1;i++)
    {
        //printf("#%d.1 %d %d\n",i,money,sum);
        if(i!=n-2&&a[i]<a[i+1])
        {
            int t=1,x=v[i];
            while(a[i]<a[i+t])
            {
                t++;
                x+=v[i+t];
            }
            money+=(x+sum)/d*a[i];
            sum=(x+sum)%d;
            i=t;
        }
        else
        {
            money+=(sum+v[i]+d-1)/d*a[i+1];
            sum=(sum+v[i])%d;
        }
        //printf("#%d.2 %d %d\n",i,money,sum);
    }
    printf("%d",money);
    return 0;
}
