#include<bits/stdc++.h>
using namespace std;
const int mn=100003;
int n;
long long ans=-1,a[mn],b[mn],c[mn];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)scanf("%lld%d%d",&a[i],&b[i],&c[i]);
    for(register int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
    }
    for(register int i=1;i<=n;++i){
        long long day=0;
        if(c[i]==0){
            day=a[i]/b[i];
            if(day*b[i]<a[i])++day;
        }
        else if(c[i]>0){
            int x=i;
            long long heigh=0;
            day=i-1;
            while(heigh<a[i])heigh=heigh+b[i]+x*c[i],++x,++day;
        }
        else{
            int x=i;
            long long heigh=0;
            day=i-1;
            while(b[i]+x*c[i]>1&&heigh<a[i])heigh=heigh+b[i]+x*c[i],++x,++day;
            if(heigh<a[i])day=day+a[i]-heigh;
        }
        if(ans==-1)ans=day;
        else ans=min(ans,day);
    }
    return printf("%lld",ans),0;
}