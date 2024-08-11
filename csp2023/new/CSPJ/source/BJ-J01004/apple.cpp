#include <iostream>
using namespace std;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n;
    cin >> n;

    int ans = -1;
    int cnt = 0;
    while(n != 0){
        cnt++;
        if(n % 3 == 0){
            n -= n / 3;
        }else if(n % 3 == 1){
            n -= (n + 2) / 3;
            if(ans == -1){
                ans = cnt;
            }
        }else{
            n -= (n + 1) / 3;
        }
    }

    cout << cnt << " " << ans;
    return 0;
}
