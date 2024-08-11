#include <iostream>
using namespace std;

string address[10001];

int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int cur = 0;
    for (int i = 1; i <= n; i++){
        int op;
        cin >> op;
        if (op == 2){
            string t, n;
            cin >> t >> n;
            if (t == "short"){
                cur = ((cur + 1) >> 1) << 1;
            } else if (t == "int"){
                cur = ((cur + 3) >> 2) << 2;
            } else if (t == "long"){
                cur = ((cur + 7) >> 3) << 3;
            }
            if (t == "byte"){
                address[cur] = n;
                cur++;
            } else if (t == "short"){
                address[cur] = address[cur + 1] = n;
                cur += 2;
            } else if (t == "int"){
                address[cur] = address[cur + 1] = address[cur + 2] = address[cur + 3] = n;
                cur += 4;
            } else {
                address[cur] = address[cur + 1] = address[cur + 2] = address[cur + 3] = address[cur + 4] = address[cur + 5] = address[cur + 6] = address[cur + 7] = n;
                cur += 8;
            }
        } else if (op == 3){
            string s;
            cin >> s;
            for (int i = 1; i <= cur; i++){
                if (address[i] == s){
                    cout << i << "\n";
                    break;
                }
            }
        } else if (op == 4){
            int a;
            cin >> a;
            if (address[a].empty()){
                cout << "ERR\n";
            } else {
                cout << address[a] << "\n";
            }
        }
    }
    return 0;
}
