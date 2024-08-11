#include<bits/stdc++.h>
typedef long long lol;
using namespace std;
int c,t;
int n,m,k,d;
struct nd{
    int l,r;
    lol v;
}tz[100002],tz2[100002];
bool cmp(nd a,nd b){
    if(a.l>b.l) return false;
    return true;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&t);
    int x,y,v;
    while(t--){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=1;i<=m;++i){
            scanf("%d%d%d",&x,&y,&v);
            tz[i]={x-y+1,x,v};
        }
        sort(tz+1,tz+m+1,cmp);
        int ll=tz[1].l,rr=tz[1].r,cnt=0;
        lol vv=tz[1].v;
        for(int i=2;i<=m;++i){
            if(tz[i].l<=rr){
                if(tz[i].r-ll+1>k){
                    ++cnt;
                    tz2[cnt]={ll,rr,vv};
                    ll=tz[i].l;
                    rr=tz[i].r;
                    vv=tz[i].v;
                    continue;
                }
                rr=max(rr,tz[i].r);
                vv+=tz[i].v;
            }
            else{
                ++cnt;
                tz2[cnt]={ll,rr,vv};
                ll=tz[i].l;
                rr=tz[i].r;
                vv=tz[i].v;
            }
        }
        ++cnt;
        tz2[cnt]={ll,rr,vv};
        lol ans=0,sum;
        for(int i=1;i<=cnt;++i){
            sum=tz2[cnt].v-1ll*d*(tz2[cnt].r-tz2[cnt].l+1);
            if(sum>0) ans+=sum;
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
