#include <iostream>
#include <string>
using namespace std;
bool check(string a){
    while (a.size()){
        bool flag = 1;
        for (int i = 0; i < a.size() - 1; i ++)
            if (a[i] == a[i + 1]){
                a.replace(i, 2, "");
                flag = 0;
                break;
            }
        if (flag) return 0;
    }
    return 1;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    string a;
    int n, cnt = 0;
    cin >> n >> a;
    for (int i = 0; i < a.size() - 1; i ++)
        for (int j = i + 1; j < a.size(); j += 2)
            if (check(a.substr(i, j - i + 1))) cnt ++;
    cout << cnt << endl;
    return 0;
}
