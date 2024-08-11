#include<iostream>
#include<vector>
using namespace std;
long long dp[1004][1004];
vector<int>qst[1001];
vector<int>rew[1001];
int c,t;
int n,m,k,d;
void p4(){
    scanf("%d%d%d%d",&n,&m,&k,&d);
    for(int i = 1;i<=n;i++){
            qst[i].clear();
            rew[i].clear();
        for(int j = 1;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    int x,y,v;
    for(int i = 1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&v);
        qst[x].push_back(y);
        rew[x].push_back(v);
    }
    long long lst_max = -0;
    long long int nt;
    for(int i = 1;i<=n;i++){
        nt = lst_max;
        dp[i][0] = lst_max;
        for(int j = 1;j<=k&&j<=i;j++){
            long long int tot = 0;
            for(int k = 0;k<qst[i].size();k++){
                if(qst[i][k]<=j)tot+=rew[i][k];
            }
            dp[i][j] = dp[i-1][j-1]+tot-d;
            nt = max(dp[i][j],nt);
        }
        lst_max = nt;
    }
    cout <<lst_max << endl;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        p4();
    }
}

