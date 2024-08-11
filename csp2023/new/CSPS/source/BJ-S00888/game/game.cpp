#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000010;
const int S=27;
ll n,/*pre[N][S],fir[N][S],*/a[N],sum[N],ans,cnt[N];
bool dp[3010][3010];
char s[N];
bool vis[N];
stack<char> st;
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);
    scanf("%s",s+1);
    if(n<=3000){
        for(int i=1;i<n;i++) if(s[i]==s[i+1]) dp[i][i+1]=1,ans++;
        for(int len=4;len<=n;len+=2){
            for(int l=1;l<=n;l++){
                int r=l+len-1;
                if(r>n) break;
                if(s[l]==s[r]&&dp[l+1][r-1]) dp[l][r]=true,ans++;
                else for(int i=l;i<=r;i++){
                    if(dp[l][i]&dp[i+1][r]){
                        dp[l][r]=true;ans++;
                        break;
                    }
                }
            }
        }
        printf("%lld\n",ans);
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(st.empty()||st.top()!=s[i]) a[i]=1,st.push(s[i]);
        else a[i]=-1ll,st.pop();
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];//,pre[i][sum[i]]=1;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            cnt[sum[i]]++;
        }
        else{
            ans+=cnt[sum[i]];
        }
    }
    printf("%lld\n",ans);
    /*
    for(int i=0;i<=26;i++) for(int j=1;j<=n;j++) pre[j][i]+=pre[j-1][i];
    for(int i=0;i<=26;i++){
        for(int j=n;j>=1;j--){
            if(sum[j]==i) fir[j][i]=j;
            else fir[j][i]=fir[j+1][i];
        }
    }
    //for(int i=1;i<=n;i++) cerr<<sum[i]<<" ";cerr<<endl;
    for(int i=1;i<=n;i++){
        if(a[i]==-1) continue;
        int pos=sum[i]==1?n:fir[i][sum[i]-2];
        if(!pos) pos=n;
        ans+=pre[pos][sum[i]-1]-pre[i-1][sum[i]-1];
        //cerr<<i<<" "<<ans<<endl;
    }
    printf("%lld\n",ans);
    */
}
