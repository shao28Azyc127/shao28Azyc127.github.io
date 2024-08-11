#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,c,t,ind,indd;
long long d,dp[1005][1005],v,ans,dd[1005],tmp;
struct stu{
    int l;
    int r;
    int len;
    long long val;
}str[100005];
void wk(){
    ans=0;
    for(int i=1;i<=m;i++){
        tmp=(long long)d*str[i].len;
        tmp+=str[i].val;
        if(tmp>0)
            ans+=tmp;
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d%d%lld",&n,&m,&k,&d);
        d=0-d;
        for(int i=1;i<=m;i++){
            scanf("%d%d%lld",&x,&y,&v);
            str[i].l=x-y+1;
            str[i].r=x;
            str[i].len=y;
            str[i].val=v;
        }
        if(c==17||c==18){
            wk();
            continue;
        }
        for(int i=1;i<=n;i++){
            dd[i]=dd[i-1];
            dp[i][0]=0;
            for(int j=1;j<=min((i-1),k);j++)
                dp[i][0]=max(dp[i][0],dp[i-1][j]);
            dp[i][0]=0;
            for(int j=1;j<=min(i,k);j++){
                dp[i][j]=dp[i-1][j-1]+d;
                for(int kk=1;kk<=m;kk++){
                    if(str[kk].r==i&&str[kk].len<=j)
                        dp[i][j]+=str[kk].val;
                }
                dd[i]=max(dd[i],dp[i][j]+dd[i-j-1]);
            }
        }
        printf("%lld\n",dd[n]);
    }
    return 0;
}