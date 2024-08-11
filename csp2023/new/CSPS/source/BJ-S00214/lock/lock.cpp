#include <bits/stdc++.h>
using namespace std;
struct lock{
    int number[6];
};
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    struct lock l[n + 10];
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 5;j++){
            cin >> l[i].number[j];
        }
    }
    if(n == 1){
        cout << 81;
        return 0;
    }
    int ans = 0;
    for(int i = 1;i <= 5;i++){
        bool ok = false;
        int thisone = l[1].number[i];
        for(int j = 2;j <= n;j++){
            if(l[j].number[i] != thisone){
                ok = true;
                break;
            }
        }
        if(ok){
            ans += 10 - n;
        }
    }
    if(n == 2){
        for(int i = 1;i <= 5;i++){
            int thisone = l[1].number[i];
            for(int j = 2;j <= n;j++){
                if(l[j].number[i] != thisone){
                    ans += 2;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
