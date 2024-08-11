#include<bits/stdc++.h>
using namespace std;
const long long maxn = 25;
bool hasRun[maxn];
long long c,t,n,m,k,d,ans = 0;
vector<pair<long long,long long> > chal[maxn];
void dfs(long long cnt) {
    if(cnt >= n) {
        long long ret = 0;
        for(long long i = 0; i < n; i++) {
            ret -= hasRun[i]*d;
        }
        long long curramn = 0;
        for(long long i = 0; i < n; i++) {
            if(hasRun[i] == true) curramn++;
            else curramn = 0;
            for(long long j = 0; j < chal[i].size(); j++) {
                if(chal[i][j].first <= curramn) ret += chal[i][j].second;
            }
            if(curramn > k) return;
        }
        ans = max(ans,ret);
        return;
    }
    hasRun[cnt] = false;
    dfs(cnt+1);
    hasRun[cnt] = true;
    dfs(cnt+1);
}
int main () {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--) {
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        ans = 0;
        for(long long i = 0; i < n; i++) {
            while(chal[i].size() > 0) chal[i].pop_back();
        }
        if(n > maxn) {
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        for(long long i = 0; i < m; i++) {
            long long a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            chal[a-1].push_back(make_pair(b,c));
        }
        dfs(0);
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
