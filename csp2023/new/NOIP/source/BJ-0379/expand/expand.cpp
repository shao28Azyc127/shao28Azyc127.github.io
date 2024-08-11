#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q;
int x[N],y[N],x1[N],y2[N],kx,ky,p,v;
bool check()
{

    if(x1[1]>y2[1]&&x1[n]>y2[m])
    {
        int i=1,j=1;
        while(i<n||j<m)
        {
            if(x1[i]<=y2[j])return false;
            if(x1[i]>y2[j+1]||i==n)
            {
                j++;
            }
            else if(x1[j+1]>y2[j]||j==m)
            {
                i++;
            }
        }
        return true;
    }
    if(x1[1]<y2[1]&&x1[n]<y2[m])
    {
        int i=1,j=1;
        while(i<n||j<m)
        {
            if(x1[i]>=y2[j])return false;
            if(x1[i]<y2[j+1]||i==n)
            {
                j++;
            }
            else if(x1[j+1]<y2[j]||j==m)
            {
                i++;
            }
        }
        return true;
    }
    return false;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d %d %d %d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)scanf(" %d",&x[i]);
    for(int i=1;i<=m;i++)scanf(" %d",&y[i]);


    printf("%d",check());
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=n;j++)x1[j]=x[j];
        for(int j=1;j<=m;j++)y2[j]=y[j];
        scanf("%d %d",&kx,&ky);
        while(kx--)
        {
            scanf("%d %d",&p,&v);
            x1[p]=v;
        }
        while(ky--)
        {
            scanf("%d %d",&p,&v);
            y2[p]=v;
        }
        printf("%d",check());
    }
    return 0;
}
