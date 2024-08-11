#include <iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    double rest;
    long a[100000]={0};
    long p[100000]={0};
    long dis=0;
    long n,e;
    long total=0;
    long sum;
    int i=0;
    cin>>n>>e;
    cout<<n<<e<<endl;
    for(int i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    while(dis<n-1){
        for(i=dis;i<n-1;i++)
        {
            if(p[dis]>p[i])
            {
                sum=0;
                for(int j=dis;j<i;j++)
                {
                    sum+=a[j];
                }
                total+=(double)(sum*p[dis]+0.9999999)/e+0.9999999;
                cout<<total;
                dis=i;
            }
        }
        if(i==n-1)
        {
            sum=0;
            for(int j=dis;j<n-1;j++)
            {
                sum+=a[j];
            }
            total+=(double)(sum*p[dis]+0.9999999)/e+0.9999999;
            cout<<total;
            break;
        }
    }
    total--;
    cout<<total;
    return 0;
}
