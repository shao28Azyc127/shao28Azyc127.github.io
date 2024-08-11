#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
set<int> G[maxn];
int a[maxn],b[maxn],c[maxn];
int mp[1010][1010];
long long dp[1<<22];
int n;
int du[maxn];
long long val[maxn];
int sx[maxn];

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);

    if (n<=20){
        for (int i=0;i<n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
        for (int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--; v--;
            mp[u][v]=mp[v][u]=1;
        }

        for (int i=0;i<n;i++){
            int ans=0,num=0;
            while (1){
                ans++;
                num+=max(1,b[i]+c[i]*ans);
                if (num>=a[i]) break;
            }
            val[i]=ans;
        }

        for (int mask=0;mask<(1<<n);mask++) dp[mask]=1e9+7;
        dp[(1<<0)]=val[0];
        for (int mask=0;mask<(1<<n);mask++){
            int pc=0;
            for (int i=0;i<n;i++){
                if ((mask&(1<<i))) pc++;
            }
            for (int nxt=0;nxt<n;nxt++){
                if ((mask&(1<<nxt))) continue;
                int flag=0;
                for (int i=0;i<n;i++){
                    if ((mask&(1<<i))&&mp[i][nxt]==1){
                        flag=1; break;
                    }
                }
                if (flag==0) continue;
                dp[(mask|(1<<nxt))]=min(dp[(mask|(1<<nxt))],max(dp[mask],pc+val[nxt]));
            }
        }

        printf("%lld\n",dp[(1<<n)-1]);
        return 0;
    }

    int lian=0;
    for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].insert(v); G[v].insert(u);
        du[u]++;
        du[v]++;
    }

    for (int i=1;i<=n;i++){
        if (du[i]>2){
            lian=1; break;
        }
    }

    for (int i=1;i<=n;i++){
        if (du[i]==1){
            sx[1]=i; break;
        }
    }

    for (int i=2;i<=n;i++){
        int pr=sx[i-1];
        for (set<int>::iterator it=G[pr].begin();it!=G[pr].end();it++){
            int thi=(*it);
            sx[i]=thi; G[thi].erase(pr); break;
        }
    }

    if (lian==0){
        for (int i=1;i<=n;i++){
            int ans=0,num=0;
            while (1){
                ans++;
                num+=max(1,b[i]+c[i]*ans);
                if (num>=a[i]) break;
            }
            val[i]=ans;
        }
        for (int i=1;i<=n;i++) dp[i]=1e9+7;
        dp[sx[1]]=val[sx[1]];
        for (int i=2;i<=n;i++) dp[sx[i]]=max(dp[sx[i-1]],i-1+val[sx[i]]);
        printf("%lld\n",dp[sx[n]]); return 0;
    }
    return 0;
}