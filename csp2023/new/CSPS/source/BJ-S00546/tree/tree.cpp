#include<iostream>
#include<cmath>
using namespace std;
struct data
{
    int u,v;
};
data w[1000005];
int n;
int m[100005]={-1};
int ans=0;
int a[1000005],b[1000005],c[1000005];
bool gou()
{
    for(int i=1;i<=n;i++)
    {
        if(m[i]<a[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++)
    {
        cin>>w[i].u>>w[i].v;
    }
    ans++;
    m[1]=0;
    for(int i=1;i<=n;i++)
    {
        ans++;
        m[w[i].v]=0;
        for(int j=1;j=i;j++)
        {
            m[j]+=max(b[j]+ans*c[j],1);
        }
    }
    for(int i=1;gou();i++)
    {
        ans++;
        m[i]+=max(b[i]+ans*c[i],1);
    }
    cout<<ans;
    return 0;
}
