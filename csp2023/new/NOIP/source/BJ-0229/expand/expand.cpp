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
int id,n,m,q;
long long a[500005],b[500005];
int yuana[500005],yuanb[500005];
bool ok;
void dfs(int nowa,int nowb){
    if(nowa == n+1 && nowb == m+1){
        ok = 1;
        return ;
    }
    if(nowa == n+1){
        for(int i = nowb; i <= m; i++){
            if(a[1] < b[1] && a[n] > b[i]){
                return ;
            }else if(a[1] > b[1] && a[n] < b[i]){
                return ;
            }
        }
        ok = 1;
        return ;
    }
    if(nowb == m+1){
        for(int i = nowa; i <= n; i++){
            if(a[1] < b[1] && a[i] > b[m]){
                return ;
            }else if(a[1] > b[1] && a[i] < b[m]){
                return ;
            }
        }
        ok = 1;
        return ;
    }
    if(a[1] < b[1] && a[nowa] < b[nowb+1]) dfs(nowa,nowb+1);
    else if(a[1] > b[1] && a[nowa] > b[nowb+1]) dfs(nowa,nowb+1);

    if(a[1] < b[1] && a[nowa+1] < b[nowb]) dfs(nowa+1,nowb);
    else if(a[1] > b[1] && a[nowa+1] > b[nowb]) dfs(nowa+1,nowb);

    if(a[1] < b[1] && a[nowa+1] < b[nowb+1]) dfs(nowa+1,nowb+1);
    else if(a[1] > b[1] && a[nowa+1] > b[nowb+1]) dfs(nowa+1,nowb+1);
}
void solve(){
    if(a[1] == b[1]){
        printf("0"); return ;
    }
    if(n <= 2 && m <= 2){
        if((a[1] < b[1] && a[n] < b[m]) || (a[1] > b[1] && a[n] > b[m])) printf("1");
        else printf("0");
        return ;
    }
    if(n <= 6 && m <= 6){
        ok = 0;
        dfs(1,1);
        if(ok) printf("1");
        else printf("0");
        return ;
    }else{
        if(a[1] > b[1]){
            int now = 2;
            for(int i = 2; i <= n; i++){
                if(now > m) now = m;
                if(a[i] <= b[now]){
                    if(a[i] > b[now-1]) continue;
                    else if(a[i-1] > b[now]) now++;
                    else{
                        printf("0"); return ;
                    }
                }else now++;
            }
            printf("1");
        }else{
            int now = 2;
            for(int i = 2; i <= n; i++){
                if(now > m) now = m;
                if(a[i] >= b[now]){
                    if(a[i] < b[now-1]) continue;
                    else if(a[i-1] < b[now]) now++;
                    else{
                        printf("0"); return ;
                    }
                }else now++;
            }
            printf("1");
        }

    }

}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    id = read(),n = read(),m = read(),q = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= m; i++) b[i] = read();
    for(int i = 1; i <= n; i++) yuana[i] = a[i];
    for(int i = 1; i <= m; i++) yuanb[i] = b[i];
    solve();
    while(q--){
        int kx,ky; kx = read(),ky = read();
        for(int i = 1; i <= kx; i++){
            long long vx,ux; vx = read(),ux = read();
            a[vx] = ux;
        }
        for(int i = 1; i <= ky; i++){
            long long vy,uy; vy = read(),uy = read();
            b[vy] = uy;
        }
        solve();
        for(int i = 1; i <= n; i++) a[i] = yuana[i];
        for(int i = 1; i <= m; i++) b[i] = yuanb[i];
    }
    return 0;
}
