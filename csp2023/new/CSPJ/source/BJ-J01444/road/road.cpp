#include<bits/stdc++.h>
using namespace std;
int a[100005];
int jl[100005];
int jg[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,ans=0,yj,y=0;
    a[0]=999999;
printf("%d",a[0]);
    scanf("%d",n);
    scanf("%d",yj);
//printf("%d",n);
    for(int i=1;i<n;i++)
        scanf("%d",&jl[i]);//1 cun di 1 ge yu 2 ge de jv li
//printf("%d",jl[n]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&jg[i]);
//rintf("%d",jg[i]);
        if(jg[i]<=a[i-1])//1 cun di 1 ge de you jia
            a[i]=jg[i];
        else
            a[i]=a[i-1];// 1 cun qian mian de zui you jia
    }
    for(int i=n;i>1;i--)
        jl[i-1]+=jl[i];//qian zhui he
    int l=jl[1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i+1])
        {
            int yy=(l-jl[i+1]-y)/yj;
            l=jl[i+1];
            if(jl[i+1]%yj)
                yy++;
            y=yy*yj-jl[i+1];
            ans+=yy*a[i];
//printf("%d",ans);
        }
    }
    printf("%d",ans);
    return 0;
}
