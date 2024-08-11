#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct Node
{
    int v,b,id;
};
Node a[100005];
int s[100005];
bool cmp(Node x,Node y)
{
    if(x.v!=y.v) return x.v<y.v;
    return x.b<y.b;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n;
    double d,sum=0,ans=0;
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>a[i].v;
        s[i]=s[i-1]+a[i].v;
        sum+=a[i].v;
        a[i].id=i;
    }
    for(int i=1;i<n;i++) cin>>a[i].b;
    int v;
    cin>>v;
    v=n;
    sort(a+1,a+n,cmp);
    if(a[1].id==1)
    {
        cout<<ceil(sum/d)*a[1].b;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        if(v>a[i].id)
        {
            ans+=ceil(double(s[v-1]-s[a[i].id-1])/d)*a[i].b;
            v=a[i].id;
            cout<<ans<<" ";
        }
        if(v==1) break;
    }
    cout<<ans;
    return 0;
}
