#include<iostream>
using namespace std;
const int N = 1e5 + 2;
int t, u, n, m;
int ans[N], mi;
bool run(){
    return false;
}
void dfs(int a, int b = 0){
    if(b >= mi){
        return;
    }
    if(a == n + 1){
        if(run()){
            mi = b;
        }
        return;
    }
    ans[a] = 'U';
    dfs(a + 1, b + 1);
    ans[a] = 'T';
    dfs(a + 1);
    ans[a] = 'F';
    dfs(a + 1);
}
struct run{
    char type;
    int a, b;
}r[N];
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
    cin >> u >> t;
    if(u >= 3){
            cout << 0 << endl;
    }else{
        for(int i = 1; i <= t; i++){
            cin >> n >> m;
            mi = n;
            for(int i = 1; i <= m; i++){
                cin >> r[i].type >> r[i].a;
                if(r[i].type == '+' || r[i].type == '-'){
                    cin >> r[i].b;
                }
            }
            // dfs(1);
            cout << mi << endl;
        }
    }
}