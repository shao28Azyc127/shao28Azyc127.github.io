#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int C,T,n,m,k,d,x[N],y[N],v[N];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=1;i<=m;i++)scanf("%d%d%d",&x[i],&y[i],&v[i]);
        long long ans=0;
        if(n<=20){
            for(int i=0;i<(1<<n);i++){
                int st[22],a[22],tmpi=i,tmp=0;
                long long res=0;
                for(int j=1;j<=n;j++){
                    a[j]=tmpi&1;
                    tmpi>>=1;
                }
                bool flag=true;
                for(int j=1;j<=n;j++){
                    if(a[j]==1)tmp++,res-=d;
                    else tmp=0;
                    st[j]=tmp;
                    if(st[j]>k){
                        flag=false;
                        break;
                    }
                }
                if(!flag)continue;
                for(int i=1;i<=m;i++)
                    if(st[x[i]]>=y[i])res+=v[i];
                ans=max(ans,res);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//Workingmen of all countries, unite!