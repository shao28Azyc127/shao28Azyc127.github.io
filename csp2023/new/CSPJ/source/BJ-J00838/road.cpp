#include<cstdio>
using namespace std;
const int N=1e5+5;
const long long MAXN=1e15;
long long dp[N][2];//dp[i][0]min_cost dp[i][1]remain_length
long long v[N];//v[i] 1~i
int c[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,curl,curo,curr;
    scanf("%d%d",&n,&d);
    for(int i=2;i<=n;++i){
        scanf("%d",&v[i]);
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;++i)scanf("%d",&c[i]);
    dp[1][0]=dp[1][1]=0;
    for(int i=2;i<=n;++i){
        //printf("i:%d\n",i);
        dp[i][0]=dp[i][1]=MAXN;
        for(int j=1;j<i;++j){
            //printf("j:%d\n",j);
            curl=v[i]-v[j];
            curo=(curl-dp[j][1])/d+((curl-dp[j][1])%d==0?0:1);
            curr=curo*d+dp[j][1]-curl;
            //printf("curl:%d curo:%d curr:%d\n",curl,curo,curr);
            if(curo*c[j]+dp[j][0]<dp[i][0]){
                dp[i][0]=curo*c[j]+dp[j][0];
                dp[i][1]=curr;
            }else{
                if(curo*c[j]+dp[j][0]<dp[i][0]&&curr>dp[i][1]){
                    dp[i][0]=curo*c[j]+dp[j][0];
                    dp[i][1]=curr;
                }
            }
        }
        //printf("\n");
    }
    //for(int i=1;i<=n;++i)printf("%lld ",dp[i][0]);
    //printf("\n");
    //for(int i=1;i<=n;++i)printf("%lld ",dp[i][0]);
    //printf("\n");
    printf("%lld",dp[n][0]);
    return 0;
}
