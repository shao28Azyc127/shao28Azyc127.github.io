#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, a[100010];
int b[100010], cmp;
struct node{
    char c;
    int x, y;
}xx[100010];
int ans = 0x3f3f3f3f;
void work(){
    for(int i = 1; i <= n; i++){
        b[i] = a[i];
    }
    for(int i = 1; i <= m; i++){
        if(xx[i].c == '+'){
            b[xx[i].x] = b[xx[i].y];
        }else if(xx[i].c == '-'){
            if(b[xx[i].y] == 1){
                b[xx[i].x] = 0;
            }else if(b[xx[i].y] == 0){
                b[xx[i].x] = 1;
            }else if(b[xx[i].y] == -1){
                b[xx[i].x] = -1;
            }
        }else if(xx[i].c == 'T'){
            b[xx[i].x] = 1;
        }else if(xx[i].c == 'F'){
            b[xx[i].x] = 0;
        }else if(xx[i].c == 'U'){
            b[xx[i].x] = -1;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            return;
        }
        if(a[i] == -1){
            cnt++;
        }
    }

    if(cnt <ans){
        ans = cnt;
    }
}
void dfs(int id){
    if(id > n){
        work();
        return;
    }
    a[id] = 0;
    dfs(id+1);
    a[id] = 1;
    dfs(id +1);
    a[id] = -1;
    dfs(id+1);
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t;
    cin >> c >> t;

    if(c == 3 || c == 4){
        while(t--){

            cin >> n >> m;
            memset(a, 0, sizeof(a));
            for(int i = 1; i <= m; i++){
                char c;
                int cmp;
                cin >> c >> cmp;
                if(c == 'T'){
                    a[cmp] = 0;
                }else if(c == 'F'){
                    a[cmp] = -1;
                }else{
                    a[cmp] = 1;
                }
            }
            ans = 0;
            for(int i = 1; i <= n; i++){
                if(a[i] == 1){
                    ans++;
                }
            }
            cout <<ans <<endl;
        }
        return 0;
    }
    if(c == 5 || c == 6){ // false
        while(t--){


            cin >> n >> m;
            memset(a, 0, sizeof(a));
            for(int i = 1; i <= m; i++){
                char c;
                int x;
                cin >>c >>x;
                if(c == 'U'){
                    a[x] = 1;
                }else if(c == '+'){
                    int y;
                    cin >>y;
                    a[x] = a[y];
                }
            }
            ans = 0;
            for(int i = 1; i <= n; i++){
                if(a[i] == 1){
                    ans++;
                }
            }
            cout <<ans <<endl;
        }
        return 0;
    }
    if(c == 7 ||c == 8){ //false
        while(t--){
            cout <<0 <<endl;
        }
        return 0;
    }
    if(c == 1 || c == 2){
        while(t--){
        ans = 0x3f3f3f3f;
        cin >> n >>m;
        for(int i = 1; i <= m; i++){
            char c;
            cin >>c;
            xx[i].c = c;
            if(c == '+'|| c == '-'){
                int x, y;
                cin >>x >>y;
                xx[i].x = x;
                xx[i].y = y;
            }else{
                int x;
                cin >> x;
                xx[i].x = x;
            }
        }
        dfs(1);

        cout <<ans <<endl;
        }
        return 0;
    }
    return 0;
}
//let me pass let me pass pleas!!!!!!!!!!!!!!!!
//sto dzd orz
//sto kksc03 orz
//sto chen_zhe orz
//sto lxl orz
//sto Shan_creeper orz
//NOIP is too hard for me, I'm gonna dead
//NOIP AK keqi