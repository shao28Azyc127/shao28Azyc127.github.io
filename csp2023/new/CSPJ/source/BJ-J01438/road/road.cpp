#include <iostream>
using namespace std;
int a[100005],b[100005],n,d,x,sum,maxx=100005,maxi,sheng;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    a[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        a[i]=a[i-1]+x;
    }
    for(int i=1;i<=n;i++)//5 4 10 10 10 10 9 8 9 6 5
    {
        cin>>b[i];
        if(b[i]<maxx)
        {
            maxx=b[i];
            maxi=i;
        }
    }

    int i=1;
    for(;i<n;)
    {
        bool jin=true;
        for(int j=i+1;j<=n&&jin==true;j++)
        {
            if(b[i]>b[j])
            {
                if((a[j]-a[i])%d==0)
                {
                    sum+=(a[j]-a[i])/d*b[i];
                }
                else
                {
                   if(sheng>=(a[j]-a[i])%d)
                   {
                       sum+=(a[j]-a[i])/d*b[i];
                       sheng-=(a[j]-a[i])%d;
                   }
                   else
                   {
                       sum+=(((a[j]-a[i])/d*b[i])+b[i]);
                       sheng+=b[i]-((a[j]-a[i])%d);
                   }
                }
                cout<<sum<<" "<<i<<j<<endl;
                i=j;
                jin=false;
            }
        }
        if(jin==true)
        {
            if((a[n]-a[i])%d==0)
            {
                sum+=(a[n]-a[i])/d*b[i];
            }
            else
            {
                sum+=(((a[n]-a[i])/d*b[i])+b[i]);
            }
            cout<<sum;
            return 0;
        }
    }
    cout<<sum;
    return 0;
}
