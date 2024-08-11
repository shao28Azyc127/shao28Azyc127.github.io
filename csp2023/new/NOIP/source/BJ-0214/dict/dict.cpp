#include<bits/stdc++.h>
using namespace std;

const int MAXN=3000+10;
const int MAXM=3000+10;
int cnt[MAXN][32];
int sum[MAXN][32];
char str[MAXM];
int N,M;

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%s",str);
        for(int j=0;j<M;j++) cnt[i][str[j]-'a']++;
        for(int j=26;j>=0;j--) sum[i][j]=sum[i][j+1]+cnt[i][j];
    }
    for(int i=1;i<=N;i++){
        bool flag=true;
        for(int j=1;j<=N;j++){
            if(i==j) continue;
            int flag2=-1,k;
            for(k=0;k<25;k++){
                //printf("(%d,%d) (%d,%d)\n",cnt[i][k],sum[i][k],cnt[j][k],sum[j][k]);
                if(cnt[i][k]!=0 && sum[j][k+1]){
                    flag2=1;
                    break;
                }
            }
            if(flag2==-1){
                //printf("%d %d\n",j,k);
                flag=false;
                break;
            }
        }
        // printf("%d\n",flag);
        printf("%d",flag);
    }
    puts("");
    return 0;
}