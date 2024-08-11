#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],mi,Lu,ans;
struct dian
{
    int you,hao;
}a[100005];
bool cmp1(dian a,dian b)
{
    return a.you<b.you;
}
bool cmp2(dian a,dian b)
{
    return a.hao<b.hao;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].you;
        a[i].hao=i;
    }
    sort(a+1,a+n,cmp1);
    for(int i=1;i<=n;i++)
    {
        if(a[i].hao==1)
        {
            mi=i;
            break;
        }
    }
    sort(a+1,a+mi+1,cmp2);
    for(int i=1;i<=mi;i++)
    {
        Lu=0;
        if(i<mi)
            for(int j=a[i].hao;j<a[i+1].hao;j++)
            {
                Lu+=v[j];
            }
        else
            for(int j=a[i].hao;j<n;j++)
            {
                Lu+=v[j];
            }
        ans+=Lu/d*a[i].you;
    }
    cout<<ans;
    return 0;
}
