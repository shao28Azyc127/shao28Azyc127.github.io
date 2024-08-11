#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    bool a[n] = {0};
    int ans = 0;
    int t = 0;
    int m;
    while(++ans){
		int k = 3;
        for(int i = 0; i < n; ++ i){
            if(a[i]) continue;
            if(k == 3){
                k = 0;
                a[i] = 1;
				if(i + 1 == n) m = ans;
                ++ t;
                if(t == n){
                    cout << ans << ' ' << m <<endl;
                    return 0;
                }
            }
            ++k;
        }
    }
    return 0;
}
