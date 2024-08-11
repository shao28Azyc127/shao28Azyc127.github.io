#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,m=0,ans=0;
    cin>>n>>d;
    for(int i=1; i<=n-1; i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n; i++)
    {
        cin>>b[i];
    }
    for(int i=1; i<n;)
    {
        int h=i;
        long long dis=0;
        while(h<n&&b[h]<b[h+1])
        {
            dis+=a[h];
            h++;
        }
        dis+=a[h];
        h++;
        dis-=m;
        m=max(0ll,0-dis);
        dis=max(dis,0ll);
        int t=dis/d;
        bool flag=(dis%d!=0);
        ans+=(t+flag)*b[i];
        m+=(t+flag)*d-dis;
        //cout<<dis<<" "<<m<<" "<<ans<<" "<<t<<endl;
        i=h;
    }
    cout<<ans<<endl;
    return 0;
}

