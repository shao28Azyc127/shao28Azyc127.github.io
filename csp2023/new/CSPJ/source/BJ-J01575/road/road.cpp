#include<bits/stdc++.h>
using namespace std;
int n,d,a[100003],v[100003];
long long ans,s;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(register int i=1;i<n;++i)scanf("%d",&v[i]);
    for(register int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(register int i=1;i<n;){
        int pos=i;
        while(a[pos]>=a[i])s+=v[pos],++pos;
        if(s%d==0){
            long long cnt=s/d;
            ans+=cnt*a[i],
            s=0,
            i=pos;
        }else{
            long long cnt=s/d+1;
            ans+=cnt*a[i],
            s=s-cnt*d,
            i=pos;
        }
        //printf("a%d %d %lld\n",pos,s,ans);
    }
    return printf("%lld\n",ans),0;
}