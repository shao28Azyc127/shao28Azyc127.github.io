#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int y=0,ans=0,zong=0;
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        zong+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        int p=0;
        while(p*d+y<v[i])
        {
            p++;
        }
        y+=p*d-v[i];
        ans+=p*a[i];
        zong-=v[i];
        for(int j=i+1;j<=n;j++)
        {
            int x=0,z=0;
            if(a[i]<=a[j]&&x+y<zong)
            {
                x+=v[j];
                while(p*d+y<v[j])
                {
                    p++;
                }
                y+=p*d;
                ans+=p*a[i];
            }
            else
            {
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
