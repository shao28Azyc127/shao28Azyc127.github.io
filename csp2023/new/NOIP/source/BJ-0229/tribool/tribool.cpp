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

int n,m;
struct caozuo{
    char opt;
    int iii,jjj;
}a[100005];//xuliecaozuo
int quzhi[100005];//mei ge shu de qu zhi
int zhixingwan[100005];
int ans;
void dfs(int now){
    if(now == n+1){
        for(int i = 1; i <= n; i++) zhixingwan[i] = quzhi[i];
        for(int i = 1; i <= m; i++){
            if(a[i].opt == 'T') zhixingwan[a[i].iii] = 0;
            if(a[i].opt == 'F') zhixingwan[a[i].iii] = 1;
            if(a[i].opt == 'U') zhixingwan[a[i].iii] = 2;
            if(a[i].opt == '+') zhixingwan[a[i].iii] = zhixingwan[a[i].jjj];
            if(a[i].opt == '-'){
                if(zhixingwan[a[i].jjj] == 0) zhixingwan[a[i].iii] = 1;
                else if(zhixingwan[a[i].jjj] == 1) zhixingwan[a[i].iii] = 0;
                else if(zhixingwan[a[i].jjj] == 2) zhixingwan[a[i].iii] = 2;
            }
        }
        for(int i = 1; i <= n; i++) if(zhixingwan[i] != quzhi[i]) return ;
        int cnt = 0;
        for(int i = 1; i <= n; i++) cnt += (zhixingwan[i] == 2);
        ans = min(ans,cnt);
        return ;
    }else{
        quzhi[now] = 0;//T
        dfs(now+1);
        quzhi[now] = 1;//F
        dfs(now+1);
        quzhi[now] = 2;//U
        dfs(now+1);
    }
}
int bing[100005];
int geshu[100005];
bool can[100005];
int getfa(int now){
    if(now == bing[now]) return now;
    else return bing[now] = getfa(bing[now]);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int id,Txx; id = read(),Txx = read();
    if(id <= 2){//bao sou suo you ke neng xing
        while(Txx--){
            memset(quzhi,0x7f,sizeof(quzhi));
            memset(zhixingwan,0x7f,sizeof(zhixingwan));
            n = read(),m = read();
            for(int i = 1; i <= m; i++){//input
                cin >> a[i].opt;
                if(a[i].opt == '+' || a[i].opt == '-') a[i].iii = read(),a[i].jjj = read();
                else a[i].iii = read();
            }
            ans = n;//duo ce yao gui ling
            dfs(1);
            print(ans); printf("\n");
        }
        return 0;
    }
    if(id == 3 || id == 4){
        while(Txx--){
            memset(quzhi,0x7f,sizeof(quzhi));
            n = read(),m = read();
            for(int i = 1; i <= m; i++){
                char opt; cin >> opt;
                int iii; iii = read();
                if(opt == 'T') quzhi[iii] = 0;
                if(opt == 'F') quzhi[iii] = 1;
                if(opt == 'U') quzhi[iii] = 2;
            }
            int ans = 0;
            for(int i = 1; i <= n; i++) if(quzhi[i] == 2) ans++;
            print(ans); printf("\n");
        }
    }
    if(id == 5 || id == 6){
        while(Txx--){
            memset(quzhi,0,sizeof(quzhi));
            memset(can,0,sizeof(can));
            n = read(),m = read();
            for(int i = 1; i <= n; i++) geshu[i] = i;
            for(int i = 1; i <= m; i++){
                cin >> a[i].opt;
                if(a[i].opt == 'U'){
                    a[i].iii = read();
                    geshu[a[i].iii] = 0;
                }
                if(a[i].opt == '+'){
                    a[i].iii = read(),a[i].jjj = read();
                    if(a[i].iii == a[i].jjj) continue;
                    if(geshu[a[i].jjj] == 0) geshu[a[i].iii] = 0;
                    else geshu[a[i].iii] = geshu[a[i].jjj];
                }
            }
            int ans = 0;
            for(int i = 1; i <= n; i++) bing[i] = i;
            for(int i = 1; i <= n; i++){
                if(geshu[i] != 0){
                    int fa = getfa(i),fb = getfa(geshu[i]);
                    bing[fa] = fb;
                }else bing[i] = 0;
            }
            for(int i = 1; i <= n; i++) bing[i] = getfa(bing[i]);
            for(int i = 1; i <= n; i++) if(!bing[i]) ans++;
            print(ans); printf("\n");
        }
    }
    return 0;
}
/*
8 16
+ 3 3
+ 6 7
+ 6 8
+ 2 7
+ 8 6
U 2
U 3
U 6
U 6
+ 2 8
+ 3 7
U 5
+ 5 8
U 2
+ 1 8
U 4
*/
