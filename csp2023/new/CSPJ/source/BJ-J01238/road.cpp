#include<bits/stdc++.h>
using namespace std;
int a[1000005],v[1000005];
int n,d;
int sum=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)cin>>v[i];
    for(int i=0;i<n;i++)cin>>a[i];
    int yuu=0;
    for(int i=0;i<n;)
    {
        int u=a[i],lusum=0,j=i;
        bool f=1;
        while(a[j]>=u)
        {
            if(j>=n-2)
            {
                i=n-2;
                j=n-1;
                lusum+=v[n-2]-yuu;
                if(lusum<0)lusum=0;
                f=0;
                break;
            }
            j++;
            lusum+=v[j];
        }
        sum+=ceil(1.0*lusum/d)*a[i];
        int luz=ceil(1.0*lusum/d);
        yuu+=(luz*d)-lusum;
        //cout<<"lusum="<<lusum<<" j="<<j<<" i="<<i<<" sum="<<sum<<" yuu="<<yuu<<endl;
        i=j;
        if(f==0)break;
    }
    cout<<sum;
    return 0;
}

