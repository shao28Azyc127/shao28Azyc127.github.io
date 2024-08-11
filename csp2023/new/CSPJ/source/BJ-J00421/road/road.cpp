#include <bits/stdc++.h>
using namespace std;
int n,d,v[100001],sum[100001],ans,pos=100000000,cnt,c[100001];
struct ro{
    int w,id;
}a[100001],b[100001];
bool cmp(ro x,ro y){
    if(x.w!=y.w) return y.w>x.w;
    return y.id>x.id;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;++i){
        scanf("%d",&v[i]);
        sum[i]=v[i];
    }
    for(int i=n-1;i>=1;--i){
        sum[i]+=sum[i+1];
        //printf("%d ",sum[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i].w);
        c[i]=a[i].w;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i){
        //printf("%d %d\n",a[i].w,a[i].id);
        if(a[i].id<pos) {
            pos=a[i].id;
            cnt++;
            b[cnt].w=a[i].id;
            b[cnt].id=sum[a[i].id];
            //printf("%d %d\n",b[i].w,b[i].id);
        }
    }
    //printf("\n%d\n\n",cnt);
    for(int i=cnt;i>=1;--i){
        //printf("%d %d %d ",b[i].id-b[i-1].id,b[i].id,b[i-1].id);
        if((b[i].id-b[i-1].id)%d==0) ans+=(b[i].id-b[i-1].id)/d*c[b[i].w];
        else{
            int x=(b[i].id-b[i-1].id)/d+1;
            ans+=x*c[b[i].w];
            b[i-1].id-=x*d-b[i].id+b[i-1].id;
            //printf(" x:%d %d ",x,x*d-b[i].id);

        }
        //printf("%d\n",ans);

    }
    printf("%d",ans);
    return 0;
}
