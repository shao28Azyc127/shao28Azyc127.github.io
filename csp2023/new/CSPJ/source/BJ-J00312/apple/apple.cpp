#include <iostream>
using namespace std;
const int N = 1e6;
int i, num[N + 5];
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n; cin >> n;
    for (i = 1;;i++){
        int cnt = 0;
        for (int j = 1;j <= n;j++){
            if (!num[j]){
                if (cnt % 3 == 0) num[j] = i;
                cnt++;
            }
        } if (!cnt) break;
    } cout << --i << ' ' << num[n] << endl;
}
