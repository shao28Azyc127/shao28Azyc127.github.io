#include <iostream>
#include <cstdio>
using namespace std;
int v[10005],a[10005],km,temp;
long long kmsum;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,sum=0,minn=1e9;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        kmsum+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<minn)
            minn=a[i];
    }
    if(minn==a[1])
    {
        sum=kmsum/d;
        if(kmsum%d!=0)
        {
            sum++;
        }
        sum*=a[1];
        cout<<sum;
        return 0;
    }
    int kmsum1=0,m=1;
    kmsum1+=a[1];
    for(int i=1;i<=n-1;i++)
    {
        m=1;
        while(a[i]<a[i+m])
        {
            m++;
            kmsum1+=v[i];
        }

        temp=kmsum1/d;
        if(kmsum1%d!=0)
            temp++;
        sum+=temp*a[i];
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

