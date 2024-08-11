#include <bits/stdc++.h>
using namespace std;
const int manx = 1e5 + 5;
map <string, int> mp;
string t, s;
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    int op;
    long long sum = 0;
    while (n--){
        cin >> op;
        if (op == 2){
            cin >> t >> s;
            mp[s] = sum + 1;
            if (t == "byte"){
                sum += 1;
            }else if (t == "short"){
                sum += 2;
            }else if (t == "int"){
                sum += 4;
            }else if (t == "long"){
                sum += 8;
            }
        }else if (op == 3){
            cin >> s;
            if (mp[s]){
                cout << mp[s] - 1 << endl;
            }else
                cout << "ERR" << endl;
        }
    }
    return 0; 
}