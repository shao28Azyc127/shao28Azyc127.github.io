

#include <bits/stdc++.h>

using namespace std;

int n, cur, cnt;
map<string, int> ma, ans;
struct node{
    int l, r;
    string tp;
}e[200020];
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ma["byte"] = 1;
    ma["short"] = 2;
    ma["int"] = 4;
    ma["long"] = 8;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int op;
        cin >> op;
        if(op == 2){
            string s, t;
            cin >> s >> t;
            e[++cnt].tp = t;
            int u = ma[s];
            if(cur % u){
                cur = (cur / u + 1) * u;
            }
            e[cnt].l = cur, e[cnt].r = cur + u - 1;
            ans[t] = cur;
            cur = e[cnt].r + 1;
            cout << e[cnt].l << endl;
        }
        else if(op == 3){
            string s;
            cin >> s;
            cout << ans[s] << endl;
        }
        else{
            int a;
            cin >> a;
            bool b = false;
            for(int i = 1; i <= cnt; i++){
                if(a >= e[i].l && a <= e[i].r){
                    cout << e[i].tp << endl;
                    b = true;
                    break;
                }
            }
            if(!b) cout << "ERR" << endl;
        }
    }
    return 0;
}
