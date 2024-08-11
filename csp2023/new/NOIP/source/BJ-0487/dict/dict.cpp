#include<bits/stdc++.h>
#define debug printf("debug\n")
using namespace std;
const int N=3005;
int n,m;
struct S{
    char s[N];
    char smax[N];
    char smin[N];
    char cmax[N];
}c[N];
bool ans[N];
char smax[N],pmax[N];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",c[i].s+1);
        for(int j=1;j<=m;++j)c[i].smax[j]=c[i].smin[j]=c[i].s[j];
        sort(c[i].smin+1,c[i].smin+m+1);
        for(int j=1;j<=m;++j)c[i].smax[j]*=-1;
        sort(c[i].smax+1,c[i].smax+m+1);
        for(int j=1;j<=m;++j)c[i].smax[j]*=-1;
    }
    for(int i=1;i<=m;++i)smax[i]=pmax[i]='z';
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(c[j].smax[i]<=smax[i])
            {
                pmax[i]=smax[i];
                smax[i]=c[j].smax[i];
            }else if(c[j].smax[i]<=pmax[i])pmax[i]=c[j].smax[i];
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(c[j].smax[i]!=smax[i])c[j].cmax[i]=smax[i];
            else c[j].cmax[i]=pmax[i];
        }
    }
    for(int i=1;i<=n;++i)
    {
        bool flag=true;
        for(int k=1;k<=m;++k)
        {
            if(c[i].smin[k]<c[i].cmax[k])break;
            else if(c[i].smin[k]>c[i].cmax[k]){
                flag=false;
                break;
            }
        }
        ans[i]=flag;
    }
    for(int i=1;i<=n;++i)cout<<ans[i];
    return 0;
}
