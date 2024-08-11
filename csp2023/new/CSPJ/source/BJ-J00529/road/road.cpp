#include <bits/stdc++.h>
using namespace std;
int n,m,y=0;
long long zj=0;
int ju[100001];
int j[100001];
int di(int le,int ri)
{
    if(le>=ri)
    {
        return 0;
    }
    int l=1e6,xb=0;
    for(int i=le;i<=ri;i++)
    {
        if(j[i]<l)
        {
            l=j[i];
            xb=i;
        }
    }
    int ans,jl=0;
    for(int i=xb;i<=ri;i++)
    {
        jl+=ju[i];
    }
    if(jl%m==0)
    {
        ans=zj/m*l;
        y=y+zj/m;
    }
    else
    {
        ans=zj/m*l+l;
        y=y+zj/m+1;
    }
    return di(le,i-1)+ans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int l=1e6;
    cin >> n >> m;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&ju[i]);
        zj+=ju[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&j[i]);
        l=min(l,j[i]);
    }
    if(l==j[1])
    {
        if(zj%m==0)
        {
            cout << zj/m*l;
        }
        else
        {
            cout << zj/m*l+l;
        }
    }
    else
    {
        int ans=di(1,n);
        int kfc=(y*m-zj)/m;
        ans=ans-kfc*l;
        cout << ans;
    }
    return 0;
}
