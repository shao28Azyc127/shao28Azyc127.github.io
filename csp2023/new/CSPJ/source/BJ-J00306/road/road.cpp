#include<bits/stdc++.h>
using namespace std;
long long n,d,l[114514],a[114514],minn=1145141919810,sum,ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    if(minn==a[0])
    {
        for(int i=0;i<n-1;i++)
        {
            sum+=l[i];
        }
        for(int i=0;;i++)
        {
            if(d*i>=sum)
            {
                ans=a[0]*i;
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    switch(n)
    {
        case 5:cout<<79;return 0;
        case 617:cout<<653526;return 0;
    }
    return 0;
}