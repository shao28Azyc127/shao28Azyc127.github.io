#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;


map<int, int> mp;
int a[100005][7];
int b[100005][7];
char f[100005][7];
int d[100005][7];
bool g[100005][7];
bool e[100005][7];
int h[100005][7];
bool l[100005][7];
int k[100005][7];
int n,m;

void digui(int step, int u, int last, int time){
    if(time < k[step][u]) return ;
    if(step == last){
        e[step][u] = 1;
        return ;
    }
    if(b[step][u] == 0) {
        if(a[step][u] != 0){
            mp[last] = a[step][u];
        }
        else a[step][u] = last;
        return ;
    }
    if(a[step][u] != 0){
        mp[last] = a[step][u];
        return ;
    }
    else {a[step][u] = last;
    digui(b[step][u],u,last,k[step][u]);}
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t; cin >> c >> t;
    for(int u = 1; u <= t; u++){
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            char c; cin >> c;
            if(c == '+' || c == '-'){
                int x; cin >> x;
                cin >> b[x][u];
                if(c == '-') g[x][u]=1;
                f[x][u] = ' ';
                k[x][u] = i;
                if(f[b[x][u]][u] == 'U'){
                    f[x][u] = 'U';
                }
            }
            else{
                int x; cin >> x;
                f[x][u] = c;
            }
        }
        for(int i = 1; i <= n; i++){
            mp[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            if(b[i][u] != 0){
                if(a[i][u] == 0){
                    a[i][u] = i;
                    digui(b[i][u],u,i,k[i][u]);
                }
            }
            else{
                if(a[i][u] == 0){
                    a[i][u] = i;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(g[i][u]) h[a[i][u]][u]++;
        }
        for(int i = 1; i <= n; i++){
            if(e[i][u] && h[a[i][u]][u] % 2 == 1) f[i][u] = 'U';
        }
        for(int i = 1; i <= n; i++){
            if(mp[a[i][u]] != 0){
                a[i][u] = mp[a[i][u]];
            }

            //cout << a[i][u] << " ";
        }
        //cout << endl;
        for(int i = 1; i <= n; i++){
            d[a[i][u]][u]++;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(f[i][u] == 'U' && !l[a[i][u]][u]) {/*cout << i << " ";*/ans += d[a[i][u]][u]; l[a[i][u]][u] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
