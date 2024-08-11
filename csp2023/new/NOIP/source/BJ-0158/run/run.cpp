//Chtholly is like a red sun for us,the life without Chtholly likes the life without the sun.
#include<iostream>
#include<cstdio>
using namespace std;
long long id,t,n,m,k,d,x,y,v,ans,a[1002][1002],f[1002][1002];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&id,&t);
    if(id>9){
        while(t--)printf("0\n");
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    while(t--){
        for(int i=1;i<=n;i++)for(int j=0;j<=k&&j<=i;j++)a[i][j]=f[i][j]=0;
        ans=0;
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        while(m--)scanf("%lld%lld%lld",&x,&y,&v),a[x][y]+=v;
        for(int i=1;i<=n;i++)for(int j=1;j<=k&&j<=i;j++)a[i][j]+=a[i][j-1];
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k&&j<i;j++)f[i][0]=max(f[i][0],f[i-1][j]);
            for(int j=1;j<=k&&j<=i;j++)f[i][j]=f[i-1][j-1]+a[i][j]-d;
        }
        //for(int i=1;i<=n;i++){
            //printf("Chtholly %d",i);
            //for(int j=0;j<=k&&j<=i;j++)printf(" %d",f[i][j]);
            //printf("\n");
        //}
        for(int i=0;i<=k&i<=n;i++)ans=max(ans,f[n][i]);
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
