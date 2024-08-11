#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,cnt,ans=0;
    cin>>n>>d;
    cnt=n-1;
    int a[cnt];
    int b[n];
    cnt=0;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    cout<<1;
    for(int i=1;i<n;i++)
    {
        while(1)
        {
            int j=1;
            if(j*d>=a[i])
            {
                cnt+=j*b[i];
                break;
            }
            else
                j+=1;
        }
        ans+=cnt;
    }
    cout<<ans;
    return 0;
}
