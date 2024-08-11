#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 10;
int dp[maxn][31];
long long a[maxn],b[maxn],c[maxn],d[maxn];
struct jkl{
    int ne,to;
}e[maxn];
int tot = 0,h[maxn],vis[maxn];
void add(int u,int v) {
    e[++tot] = (jkl){h[u],v};
    h[u] = tot;
    }
   // priority_queue<pair<int, int>> q;
    int f(int u) {
        int x = 0;
        while (vis[u] == 0) {
         vis[u] = 1;
            u = dp[u][0];
    x++;
        }
        return x;
        }
     long long cnt[1000000];
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= 1e6; i++) {
        cnt[i] = cnt[i - 1] + i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        d[i] = a[i] / b[i] + (a[i] % b[i] != 0);
       
    }
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        add(u,v);
        dp[v][0] = u;
    }
   // for (int i = 1; (1 << i) <= n; i++) {
   //     for (int j = 1; j <= n; j++) {
  //          dp[j][i] = dp[dp[j][i - 1]][i - 1];
  //      }
   // }
    long long l = 0,r = 1e9,mid,ans = 0;
    while (l <= r) {
        mid = (l + r) >> 1;
          priority_queue<pair<int,int>> q;
   //    cout << 111;
        vis[1] = true;
        for (int i = 2; i <= n; i++) {
            q.push({-d[i],i});
           // cout << 111;
        }
        if (d[1] > mid) {
            l = mid + 1;
        //    ans = mid;
            continue;
        }
        int s = n,t = 0,sum = 0;
        while (s--) {
            int u = q.top().second;
            q.pop();
            int x = f(u);
            
            if (x + d[u] + sum > mid) {
                t = 1;
                break;
            }
            sum += x;
        }
        if (t == 1) {
            l = mid + 1;
        //    ans = mid;
        } else {
            r = mid - 1;
            ans = mid;
        }
        
    }
    cout << ans << endl;
    return 0;
}

