#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int x = n, cnt = 0, ans = 0;
    while(x){
		if(x % 3 == 1 && ans == 0)ans = cnt + 1;
        if(x % 3 == 0)x = x - x / 3;
        else x = x - (x / 3 + 1);
        cnt++;
    }
    cout << cnt << " " << ans << endl;
}
