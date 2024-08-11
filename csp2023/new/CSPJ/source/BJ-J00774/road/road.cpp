# include<iostream>
# include<algorithm>
# include<cmath>
# define endl "\n"
# define int long long
using namespace std;
const int maxn=100001;
int n, d, v[maxn], a[maxn], dp[maxn], sum[maxn], lef=0, now=1, money=0;
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i=1; i<=n-1; i++)
        cin >> v[i];
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) {
            if(a[j]>a[i] && dp[j]==0) {
                dp[j]=i;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        sum[i]=sum[i-1]+v[i-1];
    }
    while(true) {
        if(dp[now]!=0) {
            int dist=sum[dp[now]]-sum[now];
            if(lef>=dist) {
                now=dp[now];
                lef-=dist;
                continue;
            }
            int need=((dist-lef)%d==0 ? (dist-lef)/d : (dist-lef)/d+1);
            money+=need*a[now];
            lef+=need*d;
            now=dp[now];
            lef-=dist;
        } else {
            int dist=sum[n]-sum[now];
            if(lef>=dist) {
                now=dp[now];
                lef-=dist;
                break;
            }
            int need=((dist-lef)%d==0 ? (dist-lef)/d : (dist-lef)/d+1);
            money+=need*a[now];
            break;
        }
    }
    cout << money << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

