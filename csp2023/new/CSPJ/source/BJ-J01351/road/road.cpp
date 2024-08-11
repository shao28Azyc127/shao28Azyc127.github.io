#include<bits/stdc++.h>
using namespace std;
int u[100086],a[100086],s[100086],fm[100086];
int tp=0;
int sta[100086];
int updiv(int a,int b)
{
    if(a>((a/b)*b)) return a/b+1;
    return a/b;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
         cin>>u[i];
         s[i]=s[i-1]+u[i];
    }
    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
         fm[i]=n;
    }
    a[0]=-0x7fffffff;
    for(int i=1;i<=n;i++)
    {
        while(a[sta[tp]]>=a[i])
        {
            fm[sta[tp]]=i;
            tp--;
        }
        sta[++tp]=i;
    }
    int ans=0,nw=1,ww=0;
    while(nw!=n)
    {
        int y=updiv(s[fm[nw]-1]-s[nw-1]-ww,d);
        ans+=y*a[nw];
        ww+=y*d;
        ww-=(s[fm[nw]-1]-s[nw-1]);
        nw=fm[nw];
    }
    cout<<ans;
    return 0;
}
