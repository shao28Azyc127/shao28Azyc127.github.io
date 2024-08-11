#include<bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
inline int read(){
    int x = 0, w = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') w *= -1; ch = getchar();}
    while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * w;
}
struct Chal{
    int req_d;
    int req_k;
    int v;
}chal[100005];
int dp[10005][10005];
int getAll(int day, int k, int m){
    int l = 0, h = m-1;

    int ans = 0;
    for(int i=l;i<=h;i++){
        if(chal[i].req_d == day && chal[i].req_k <= k) ans += chal[i].v;
    }
    //cout<<"all:"<<ans<<endl;
    return ans;
}
bool cmp(Chal a, Chal b){
    return a.req_d < b.req_d;
}
int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c = read(), t = read();
    for(int i=0;i<t;i++){
        memset(chal, 0, sizeof(chal));
        memset(dp, 0, sizeof(dp));
        int n = read(), m = read(), k = read(), d = read();
        for(int j=0;j<m;j++){
            chal[j].req_d = read();
            chal[j].req_k = read();
            chal[j].v = read();
        }
        //cout<<"wow"<<endl;
        sort(chal, chal+m, cmp);
        for(int j=1;j<=n;j++){
            int max_d = -INF;
            for(int q=0;q<=k;q++){
                if(q > j) break;
                dp[j][0] = max(dp[j][0], dp[j-1][q]);
            }
            for(int l=1;l<=k;l++){
                if(l > j) break;
                dp[j][l] = max(dp[j-1][l], dp[j-1][l-1] - d + getAll(j, l, m));
            }
        }
        int ans = -INF;
        for(int l=0;l<=k;l++){
            if(l > n) break;
            ans = max(ans, dp[n][l]);
        }
        printf("%d\n", ans-1);
    }
}
