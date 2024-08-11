#include<bits/stdc++.h>
using namespace std;
int n,d,sum,ans=0,mon,i,shi;
int a[100005],b[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        mon=b[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(b[j]<mon)
            {
                sum+=a[i-1];
                if(sum%d==0)
                {
                    shi=sum/d;
                }
                else
                {
                    shi=(sum/d)+1;
                }
                ans+=shi*mon;
                mon=b[j];
                sum=0;
                i++;
            }
            else
            {
                sum+=a[i];
                i++;
                b[j]=0;
            }
            if(i==n-2)
            {
                sum+=a[i];
                if(sum%d==0)
                {
                    shi=sum/d;
                }
                else
                {
                    shi=(sum/d)+1;
                }
                ans+=shi*mon;
                mon=b[j];
                sum=0;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
