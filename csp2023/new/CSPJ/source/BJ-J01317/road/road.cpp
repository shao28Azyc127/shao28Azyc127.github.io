#include<bits/stdc++.h>
using namespace std;
int a[100001],d,i,j,k,n,s,t,u[100000],y;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (i=1;i<=n-1;i++)
    {
        cin>>u[i];
    }
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=1;i<=n-1;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            s+=u[j-1]/d*a[i];
            y+=s/a[i];
            if (u[j-1]%d!=0)
            {
                s+=a[i];
                y++;
            }
            if (a[j]<a[i])
            {
                break;
            }
            for (k=j;y>0;k++)
            {
                if (u[k]>=y*d)
                {
                    u[k]-=y*d;
                    y=0;
                }
                else
                {
                    y-=u[k];
                    u[k]=0;
                }
            }
        }
        if (j>=n+1)
        {
            break;
        }
        i=j;
    }
    cout<<s;
    return 0;
}
