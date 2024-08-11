#include<bits/stdc++.h>
using namespace std;

const int MAXM=100000+10;
int N,M,K,D,idx=0;
struct Task{
    int l,r,v,len;
    Task(){}
    Task(int a,int b,int c){
        l=a,r=b,v=c,len=r-l+1;
    }
} tasks[MAXM];

namespace solve1516{
    long long res=0;
    void solve(){
        res=0;
        scanf("%d%d%d%d",&N,&M,&K,&D);
        for(int i=1;i<=M;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(b>K) continue;
            if(b*D<c) res=res-b*D+c;
        }
        printf("%lld\n",res);
    }
}

namespace solve16{
    const int subMAXN=1000+10;
    const int subMAXM=1000+10;
    long long dp[subMAXN][subMAXN];
    bool cmp(Task a,Task b){
        return a.r<b.r;
     }
    void solve(){
        memset(dp,0xc0,sizeof(dp));
        sort(tasks+1,tasks+M+1,cmp);
        // for(int i=1;i<=M;i++) printf("%d ",tasks[i].r);
        // puts("");
        int now=1;
        dp[0][0]=0;
        for(int i=0;i<=N;i++){
            // printf("now=%d\n",now);
            int end=M;
            for(int j=0;j<=K;j++){
                dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
                long long cnt=0;
                for(int k=now;k<=end;k++){
                    if(tasks[k].len<=j+1 && tasks[k].r==i+1) cnt+=tasks[k].v;
                    if(tasks[k].r>i+1){
                        end=k;
                        if(j==K)
                            now=k;
                        break;
                    }
                }
                if(j!=K) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+cnt-D);
            }
        }
        long long ans=0;
        for(int j=0;j<=K;j++) ans=max(ans,dp[N][j]);
        printf("%lld\n",ans);
        // exit(0);
    }
}

// namespace solve36{
//     const int subMAXM=3000+10;
//     long long dp[subMAXM][subMAXM][2];
//     void solve(){
//         tasks[0]=Task(0,0,0);
//         sort(tasks+1,tasks+M+1,cmp);
//         memset(dp,0xc0,sizeof(dp));
//         dp[0][0][0]=0;
//         for(int i=1;i<=M;i++){
//             if(tasks[i-1].r<tasks[i].l){
//                 for(int k=0;k<i;k++)
//                     dp[i][i][1]=max(dp[i][i][1],dp[i-1][k][1]-tasks[i].len*D+tasks[i].v);
//                     dp[i][i][1]=max(dp[i][i][1],dp[i-1][k][0]-tasks[i].len*D+tasks[i].v);
//                     dp[i][i][0]=max(dp[i][i][0],dp[i-1][k][0]);
//                 continue;
//             }
//             for(int k=0;k<i;k++)
//                 dp[i][i][1]=max(dp[i][i][1],dp[i-1][k][0]-tasks[i].len*D+tasks[i].v);

            
//         }
//     }
// };

int main(){
    int C,T;
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        if(C==15 || C==16){
            solve1516::solve();
            continue;
        }
        idx=0;
        scanf("%d%d%d%d",&N,&M,&K,&D);
        for(int i=1;i<=M;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(b>K) continue;
            tasks[++idx]=Task(a-b+1,a,c);
        }
        M=idx;
        solve16::solve();
    }
    return 0;
}