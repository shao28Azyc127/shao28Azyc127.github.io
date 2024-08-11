#include<bits/stdc++.h>
using namespace std;

const int MAXN=500000+10;
int X[MAXN],Y[MAXN],inX[MAXN],inY[MAXN];
int N,M,C,Q;

namespace solve35{
    const int subMAXN=2000+10;
    bool dp[subMAXN][subMAXN];
    void solve(bool debug){
        if(Y[1]==X[1]){
            printf("0");
            return;
        }
        memset(dp,false,sizeof(dp));
        dp[1][1]=true;
        bool flag=false;
        if(Y[1]>X[1]){
            swap(X,Y);
            swap(N,M);
            flag=true;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                // if(debug) printf("(%d,%d)=%d\n",i,j,dp[i][j]);
                if(X[i+1]>Y[j]){
                    // if(debug) printf("(%d,%d)->(%d,%d) ",i,j,i+1,j);
                    dp[i+1][j]=dp[i+1][j]||dp[i][j];
                }
                if(X[i]>Y[j+1]){
                    // if(debug) printf("(%d,%d)->(%d,%d) ",i,j,i,j+1);
                    dp[i][j+1]=dp[i][j+1]||dp[i][j];
                } 
                if(X[i+1]>Y[j+1]){
                    // if(debug) printf("(%d,%d)->(%d,%d) ",i,j,i+1,j+1);
                    dp[i+1][j+1]=dp[i+1][j+1]||dp[i][j];
                }
                // if(debug) puts("");
            }
        }
        // if(debug){
        //     for(int i=1;i<=N;i++){
        //         for(int j=1;j<=M;j++){
        //             printf("%d ",dp[i][j]);
        //         }
        //         puts("");
        //     }
        // }
        printf("%d",dp[N][M]);
        if(flag) swap(N,M);
    }

};

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&C,&N,&M,&Q);
    for(int i=1;i<=N;i++) scanf("%d",X+i);
    for(int i=1;i<=M;i++) scanf("%d",Y+i);
    memcpy(inX,X,sizeof(X));
    memcpy(inY,Y,sizeof(Y));
    solve35::solve(false);
    while(Q--){
        memcpy(X,inX,sizeof(X));
        memcpy(Y,inY,sizeof(Y));
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=1;i<=a;i++){
            int c,d;
            scanf("%d%d",&c,&d);
            X[c]=d;
        }
        for(int i=1;i<=b;i++){
            int c,d;
            scanf("%d%d",&c,&d);
            Y[c]=d;
        }
        // if(Q!=3)
        solve35::solve(false);
        // if(Q==3){
        //     solve35::solve(true);
        //     for(int i=1;i<=N;i++) printf("%d ",X[i]);
        //     puts("");
        //     for(int i=1;i<=M;i++) printf("%d ",Y[i]);
        //     puts("");
        // }
    }
    puts("");
    return 0;
}