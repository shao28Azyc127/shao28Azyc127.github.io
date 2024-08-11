#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=8010;
int n,ans;
char s[maxn];
bool f[maxn][maxn];
int sum[maxn][30];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);getchar();
    for(int i=1;i<=n;i++){
        for(int j=0;j<=25;j++){
            sum[i][j]=sum[i-1][j];
        }
        scanf("%c",&s[i]);
        sum[i][(int)s[i]-'a']++;
    }
    for(int i=1;i<=n-1;i++){
        if(s[i]==s[i+1]) f[i][i+1]=1;
    }
    for(int len=4;len<=n;len+=2){
        for(int l=1;l<=n-len+1;l++){
            int r=l+len-1;
            if(f[l+1][r-1]&&s[l]==s[r]) f[l][r]=1;
            if(f[l][(r+l)>>1]&&f[(r+l)>>1+1][r]) f[l][r]=1;
            bool flag=1;
            for(int i=0;i<=25;i++){
                if((sum[r][i]-sum[l-1][i])&1){
                    flag=0;break;
                }
            }
            if(flag&&!f[l][r]){
                for(int mid=l+1;mid<=r;mid+=2){
                    if(f[l][mid]==1&&f[mid+1][r]==1){
                        f[l][r]=1;break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans+=f[i][j];
        }
    }
    printf("%d\n",ans);
    return 0;
}
