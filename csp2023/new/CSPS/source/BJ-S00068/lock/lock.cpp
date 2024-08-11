#include<bits/stdc++.h>
using namespace std;
#define int long long
#define is ________is
const int N = 10;
int n, a[N][7], ans, now[7];
int calc(int x, int y){
    if(x < y)return x + 1 + (9 - y);
    return x - y;
}
int check(int x){
    int is = 0;
    int pos = -1;
    for(int i = 1;i <= 5;i++){
        int v = a[x][i];
        if(v != now[i]){
            if(is && pos == i - 1){
                if(!(calc(a[x][i - 1], now[i - 1]) == calc(a[x][i], now[i])))return 0;
//                if(!(now[i - 1] - a[x][i - 1] == now[i] - a[x][i] || now[i - 1] - a[x][i - 1] == now[i] + (9 - a[x][i]) + 1 ||
//                     a[x][i - 1] - now[i - 1] == (9 - now[i]) + 1 + a[x][i] || now[i - 1] + (9 - a[x][i - 1]) +1 == ))return 0;
            }else if(!is){
                is = 1;
                pos = i;
//                if(now[1] == 0 && now[2]==0&&now[3]==0&&now[4] == 1 && now[5] == 4)cout << "ok" << i << "\n";
            }else{
                return 0;
            }
        }
    }
    return (is);
}
int cnt;
void dfs(int pos){
    if(pos == 6){
        ++cnt;
        for(int i = 1;i <= n;i++)
            if(!check(i))return;
//        for(int i = 1;i <= 5;i++)cout << now[i] << " ";
//        cout << "\n";
        ans++;
        return;
    }
    for(int i = 0;i <= 9;i++){
        now[pos] = i;
        dfs(pos + 1);
    }
}
signed main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= 5;j++)
            cin >> a[i][j];
    dfs(1);
    cout << ans;
    return 0;
}
/*
1
0 0 1 1 5
*/
