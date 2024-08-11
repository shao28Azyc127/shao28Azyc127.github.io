#include <bits/stdc++.h>
using namespace std;
string s;
bool check(char s){
	if ('a' <= s && 'z' >= s) return 1;
	return 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    int n;
    cin >> n >> s;
    int cnt = 0;
    int cnt1 = 0,cnt2 = 1,cnt3;
    for (int i = 1;i < n;i++){
        if (s[i] == s[i - 1]) cnt2++;
        else {
            if (cnt2 >= 4){
                if (cnt2 % 2 == 0) {
                    cnt += (cnt2 * cnt2 / 4);
                }
                else {
                    cnt += (cnt2 - 1) * (cnt2 / 2 + 1) / 2;
                }

            }
            cnt2 = 1;
        }
    }
    cout << cnt << endl;
    cnt3 = cnt;
    for (int i = 1;i < n - 1;i++){
        int j = i + 1;
        if (s[i] == s[j]) cnt1++;
        int m = i;
        if (s[m] == s[j]) cnt++;
        while (s[m] == s[j]){
            if (m - 1 < 0) break;
            if (j + 1 >= n) break;
            m = m - 1;
            j = j + 1;
            cnt++;
        }
    }
    cout << cnt;
	return 0;
}
