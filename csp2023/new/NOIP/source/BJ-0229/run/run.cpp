#include <bits/stdc++.h>
using namespace std;
__int128 read(){
    __int128 c = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        c = (c << 3) + (c << 1) + (ch ^ 48);
        ch = getchar();
    }
    return c * f;
}
void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x >= 10) print(x / 10);
    putchar(x % 10 + 48);
}
int id,Txx;
long long n,m,k,d;
long long x[100005],y[100005],z[100005];
long long ans = -1e18;
int pao[100005],sum[100005];
void dfs(int now){
    if(now == n+1){
        long long cnt = 0;
        sum[0] = 0;
        for(int i = 1; i <= n; i++){
            if(pao[i] == 1) cnt -= d;
            sum[i] = sum[i-1] + pao[i];
        }
        for(int i = k+1; i <= n; i++){
            if(sum[i] - sum[i-k-1] == k+1) return ;
        }
        for(int i = 1; i <= m; i++){
            int tian = sum[x[i]] - sum[x[i]-y[i]];
            if(tian == y[i]) cnt += z[i];
        }
        ans = max(ans,cnt);
    }else{
        pao[now] = 0;
        dfs(now+1);
        pao[now] = 1;
        dfs(now+1);
    }
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    id = read(),Txx = read();
    if(id <= 2){
        while(Txx--){
            ans = -1e18;
            memset(pao,0,sizeof(pao));
            memset(sum,0,sizeof(sum));
            n = read(),m = read(),k = read(),d = read();
            for(int i = 1; i <= m; i++){
                x[i] = read(),y[i] = read(),z[i] = read();
            }
            dfs(1);
            print(ans); printf("\n");
        }
    }


    return 0;
}
