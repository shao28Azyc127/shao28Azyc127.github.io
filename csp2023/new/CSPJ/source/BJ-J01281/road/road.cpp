#include<bits/stdc++.h>
using namespace std;
int n,d,ans,sum,b[100001];
struct E
{
    int a,b;
}a[100001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>a[i].a;
    for(int i=1;i<n;i++)cin>>a[i].b;
    int s;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        int j;
        for(j=i;a[i].b<=a[j].b;++j)
        {
            if(sum>=a[j].a)
            {
                sum-=a[j].a;
                j++;
            }
            int k=a[j].a/d;
            if ((a[j].a+sum)%d!=0&&(a[j].a+sum)%d<a[j].a)k++;
            ans+=a[i].b*(k);
            sum+=a[j].a%d;
        }
        i=j-1;
    }
    cout<<ans;
    return 0;
}
