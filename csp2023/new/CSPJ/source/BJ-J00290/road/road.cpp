#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN=1e5+5;
int n,d,a[MAXN],v[MAXN],sum=0,ans=0;



int main()
{
    int minn=1000000;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n;
    cin >> d;
    for (int i=0;i<n-1;i++)
    {
        cin >> v[i];
    }
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (int i=0;i<n-1;i++)
    {
        if (a[i]<minn)
        {
            minn=a[i];
        }
        if (sum<v[i])
        {
            ans+=minn*((v[i]-sum)/d+((v[i]-sum)%d!=0));
            sum=d*((v[i]-sum)/d+((v[i]-sum)%d!=0))-(v[i]-sum);
        }
        else{
            sum=sum-v[i];
        }
    }
    cout << ans;




    return 0;
}
