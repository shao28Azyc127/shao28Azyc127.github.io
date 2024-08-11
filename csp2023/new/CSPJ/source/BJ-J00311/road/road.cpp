#include<bits/stdc++.h>
using namespace std;
int n,a[100005],d,s,v[100005];
double o;
void f(int x)
{
    int i,j;
    if(x==n) return ;
    for(i=x+1;i<=n;i++)
    {
        if(a[i]<a[x]) break;
    }
    int vi;
    if((v[i]-v[x]-int(o*d))%d==0)
    {
        vi=(v[i]-v[x]-int(o*d))/d;
    }
    else if((v[i]-v[x])%d==0)
    {
        vi=(v[i]-v[x])/d-int(o);
    }
    else
    {
        vi=(v[i]-v[x])/d-int(o)+1;
    }
    s+=a[x]*vi;
    o=(vi*d+o*d-(v[i]-v[x]))/d;
    //cout<<o<<" "<<vi<<" "<<v[i]-v[x]<<" "<<x<<endl;
    f(i);
}
int main()
{
    int i,j;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    v[1]=0;
    for(i=2;i<=n;i++)
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[n]=0;
    f(1);
    cout<<s;
    return 0;
}
