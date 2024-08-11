#include<bits/stdc++.h>
using namespace std;
int n, s[3][10], a[3][100][10], cnt;
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            cin >> s[i][j];
    for (int i = 1; i <= n; i++) {
		cnt = 0;
		//chu1shi3hua4
        for (int j = 1; j <= 95; j++) {
            for (int k = 1; k <= 5; k++)
                a[i][j][k] = s[i][k];
        }
        //for one change
        for (int j=1; j <= 5; j++){
			for (int k = 1; k <= 9; k++) {
				cnt++;
				a[i][cnt][j] = (s[i][j] + k) % 10;
			}
        }
        //for two change
        for (int j=1; j <= 4; j++){
			for (int k = 1; k <= 9; k++) {
				cnt++;
				a[i][cnt][j] = (s[i][j] + k) % 10;
				a[i][cnt][j + 1] = (s[i][j + 1] + k) % 10;
			}
        }
    }
    if (n == 1) {
		cout << 81 << endl;
		return 0;
    }
    if (n == 2) {
		int ans = 0;
		for (int i = 1; i <= 81; i++)
		    for (int j = 1; j <= 81; j++) {
				int flag = 1;
				//cout <<"-----------" << endl;
				for (int k = 1; k <= 5; k++) {
					//cout << a[1][i][k] << " " << a[2][j][k] << endl;
					if (a[1][i][k] != a[2][j][k]) flag= 0;
				}
				//out <<"-----------" << endl;
				if (flag) {
					ans++;
					//cout << "-----------------------------point-------------------------" << endl;
				}
			}
	    cout << ans << endl;
	}
	return 0;
}