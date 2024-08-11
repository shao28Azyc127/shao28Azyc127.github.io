#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100010;
typedef long long ll;
typedef unsigned long long ull;
struct stat{
    int x, id;
}e[MAXN];

ll read()
{
    ll ans = 0;
    char inc = getchar();
    for(; inc < '0' || inc > '9'; ) inc = getchar();
    for(; inc >= '0' && inc <= '9'; ){
        ans = ans * 10 + inc - '0';
        inc = getchar();
    }
    return ans;
}

char readop()
{
    char inc = getchar();
    for(; inc != '-' && inc != '+' && inc != 'T' && inc != 'F' && inc != 'U'; ) inc = getchar();
    return inc;
}

int fa[MAXN], isu[MAXN];
int find(int pre)
{
    if(fa[pre] == pre) return pre;
    else {
        fa[pre] = find(fa[pre]);
        return fa[pre];
    }
}

void work()
{ 
    int n, m, ans = 0;
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        e[i].id = i, e[i].x = 3, fa[i] = i, fa[i + n] = i + n;
    for(int i = 1; i <= m; i++){
        char c = readop();
        int x, y;
        if(c == 'T'){
            x = read();
            e[x].id = 0, e[x].x = 1;
        }
        else if(c == 'F'){
            x = read();
            e[x].id = 0, e[x].x = 0;
        }
        else if(c == 'U'){
            x = read();
            e[x].id = 0, e[x].x = 2;
        }
        else if(c == '-'){
            x = read(), y = read();
            e[x].id = e[y].id;
            if(e[x].id == 0) {
                if(e[y].x == 1 || e[y].x == 0) e[x].x = !e[y].x;
                else e[x].x = e[y].x;
            } 
            else {
                e[x].id = -e[y].id;
            }
        }
        else{
            x = read(), y = read();
            e[x].id = e[y].id;
            if(e[x].id == 0)
                e[x].x = e[y].x;
            else e[x].id = e[y].id;
        }
    }
    //for(int i = 1; i <= n; i++) cout << e[i].id << " ";
    //cout << "\n";
    for(int i = 1; i <= n; i++){
        if(e[i].id == 0){
            if(e[i].x == 2) ans++;
        }
        else if(e[i].id < 0){   
            if(find(i) != find(-e[i].id + n)){
                
                //cout << i << " " << -e[i].id + n << " 1~~~" << fa[i] << " " << fa[1] << "||" << find(i) << " " << find(-e[i].id + n) << "\n";
                fa[find(-e[i].id + n)] = find(i);
                //cout << i << " " << -e[i].id + n << " 2~~~" << fa[i] << " " << fa[1] << "||" << find(i) << " " << find(-e[i].id + n) << "\n";
            }
        }
        else{
            if(find(i) != find(e[i].id)){
                //cout << i << " " << e[i].id << "1~!~" << fa[i] << " " << fa[e[i].id] << "||" << find(i) << " " << find(e[i].id) << "\n";
                fa[find(e[i].id)] = find(i);
                //cout << i << " " << e[i].id << "2~!~" << fa[i] << " " << fa[e[i].id] << "||" << find(i) << " " << find(e[i].id) << "\n";
                
            }   
        }
    }
    //for(int i = 1; i <= 2 * n; i++) cout << find(i) << " ";
    //cout << "\n";
    for(int i = 1; i <= n; i++){
        if(e[i].x == 2) isu[find(i)] = 1;
        if(e[i].id == 0) continue;
        //cout << "~~~" << i << " " << i + n << "||" << find(i) << " " << find(i + n) << "\n";
        if(find(i) == find(i + n)){
            //cout << "1";
            if(isu[fa[i]]) continue;
            isu[fa[i]] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(e[i].id == 0) continue;
        if(isu[fa[i]]) ans++;
    }
    printf("%d\n", ans);
    return;
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while(t--){
        work();
    }
    return 0;
}