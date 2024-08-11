#include <bits/stdc++.h>
using namespace std;
int n,n2,cnt,nclear;
bool flag;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> n;
    n2 = n;
    while (n2){
        cnt++;
        if (n2 % 3 == 0) n2 -= n2 / 3;
        else{
            if (n2 % 3 == 1 && !flag){
                flag = true;
                nclear = cnt;
            }
            n2 -= (n2 / 3 + 1);
        }
    }
    cout << cnt << " " << nclear;
    return 0;
}
