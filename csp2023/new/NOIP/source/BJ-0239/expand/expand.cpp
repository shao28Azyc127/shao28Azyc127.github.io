#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],pa[N],pb[N],pn,pm,n,m,nw;
int getans()
{
    if(a[1]==b[1]||a[n]==b[m])return 0;
    if(a[1]>b[1]&&a[n]<b[m]||a[1]<b[1]&&a[n]>b[m])return 0;
    if(a[1]<b[1])
    {
        for(int i=1;i<=max(n,m);i++)swap(a[i],b[i]);
        swap(n,m);
    }
    nw=0;
    for(int i=1;i<=n;i++)
    {
        if(nw<m&&a[i]>b[nw+1])
        {
            while(nw<m&&a[i]>b[nw+1])nw++;
        }
        else
        {
            while(nw>=1&&a[i]<=b[nw])nw--;
            if(nw==0)return 0;
        }
    }
    return nw==m;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,q;
    cin>>c>>pn>>pm>>q;
    for(int i=1;i<=pn;i++)scanf("%d",&pa[i]),a[i]=pa[i];
    for(int i=1;i<=pm;i++)scanf("%d",&pb[i]),b[i]=pb[i];
    n=pn;
    m=pm;
    cout<<getans();
    int ka,kb,id,x;
    while(q--)
    {
        scanf("%d%d",&ka,&kb);
        n=pn;
        m=pm;
        for(int i=1;i<=n;i++)a[i]=pa[i];
        for(int i=1;i<=m;i++)b[i]=pb[i];
        for(int i=1;i<=ka;i++)
        {
            scanf("%d%d",&id,&x);
            a[id]=x;
        }
        for(int i=1;i<=kb;i++)
        {
            scanf("%d%d",&id,&x);
            b[id]=x;
        }
        printf("%d",getans());
    }
    return 0;
}
