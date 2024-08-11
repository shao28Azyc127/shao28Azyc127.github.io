#include <bits/stdc++.h>
using namespace std;
int n,d;
int ans;
int sum[100100];
struct gas
{
    int m;
    int p;
}arr[100100];

int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    arr[0].m=0;
    for(int i=1;i<n;i++)
        cin>>arr[i].m;
    for(int i=0;i<n;i++)
        cin>>arr[i].p;
    //Ç°×ººÍ
    for(int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+arr[i].m;
    }



    int pos=0;
    int g=0;
    while(pos!=n-1)
    {
        int target=n-1;
        bool flag=1;
        for(int i=pos+1;i<n&&flag;i++)
        {
            if(arr[i].p<arr[pos].p)
            {
                target=i;
                flag=0;
            }
        }
        int road =sum[target]-sum[pos]-g;
        ans+=ceil((double)road/d)*arr[pos].p;
        g=ceil((double)road/d)*d-road;
        pos=target;

    }
    cout<<ans;
    return 0;

}
