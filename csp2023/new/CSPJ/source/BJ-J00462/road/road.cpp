#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int a[N],v[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,i,j,s=0,k;
    double sum=0,m,sum2=0,x;
    cin>>n>>m;
    for(i=1;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i=j)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
            {
                if(j!=n)
                {
                    x=j-1;
                }
                else
                {
                    x=j;
                }
                for(k=i;k<=x;k++)
                {
                    if(s>0)
                    {
                        if(v[k]-s<=0)
                        {
                            s-=v[k];
                            continue;
                        }
                        v[k]-=s;
                    }
                    sum+=(v[k]/m);
                    s=int(sum);
                    if(sum>s)
                    {
                        sum-=v[k]/m;
                        sum+=s*a[i]-sum2*a[i]+a[i];
                    }
                    else
                    {
                        sum-=v[k]/m;
                        sum+=v[k]/m*a[i];
                    }
                    s=s*m-v[k];
                    sum2=sum;
                }
            }
        }
    }
    sum+=0.999999;
    s=sum;
    cout<<s;
    return 0;
}
