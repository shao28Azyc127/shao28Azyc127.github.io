#include<cstdio>
using namespace std;
int n,ans;
char s[8002];
bool f[8002][8002];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<n;i++)if(s[i]==s[i+1])f[i][i+1]=true;
    for(int l=3;l<=n;l+=2){
        for(int i=1;i+l<=n;i++){
            if(f[i+1][i+l-1]&&s[i]==s[i+l])f[i][i+l]=true;
            else for(int k=1;k<=l;k+=2)if(f[i][i+k]&&f[i+k+1][i+l])f[i][i+l]=true;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j+=2){
            if(f[i][j]){
                ans++;
                //printf("Chtholly %d %d %d\n",i,j,ans);
            }
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
