#include <cstdio>
#include <algorithm>
using namespace std;
long long x[1007],y[1007],w[1007],ans,n,m,k,d;
void dfs(long long u,long long now,int lz){
    if(u>n){
        ans=max(ans,now);
        return;
    }
    if(lz!=k){
        long long la=now;
        now-=d;
        lz++;
        for(long long i=1;i<=m;i++){
            if(u==x[i] && lz>=y[i]) now+=w[i];
        }
        dfs(u+1,now,lz);
        now=la;
    }
    lz=0;
    for(long long i=1;i<=m;i++){
        if(u==x[i] && lz>=y[i]) now+=w[i];
    }
    dfs(u+1,now,0);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    long long c,t;
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=-1e18;
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(long long i=1;i<=m;i++){
            scanf("%lld%lld%lld",&x[i],&y[i],&w[i]);
        }
        dfs(1,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
�����ɣ�syh
�����������
������Ŀ�����
�����������Ժ�
��ϡ�ǵ�U��
���и�����A��
����ɸ������
��д1hҲ����!
*/