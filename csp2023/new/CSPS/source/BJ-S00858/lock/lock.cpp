#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
int n;
int loc[MAXN][10];
int g[10];
int dif[10] , tot = 0;
int ans = 0;
int main() { 
	freopen("lock.in" , "r" , stdin);
	freopen("lock.out" , "w" , stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) 
		for(int j = 1;j <= 5;j++)
			cin >> loc[i][j];
	
	for(g[1] = 0;g[1] <= 9;g[1]++)
	for(g[2] = 0;g[2] <= 9;g[2]++)
	for(g[3] = 0;g[3] <= 9;g[3]++)
	for(g[4] = 0;g[4] <= 9;g[4]++)
	for(g[5] = 0;g[5] <= 9;g[5]++) {
		bool flag = false;
		memset(dif , 0 , sizeof(dif));
		for(int i = 1;i <= n;i++) {
			tot = 0;
			for(int j = 1;j <= 5;j++) {
				dif[j] = loc[i][j] - g[j];
				if(dif[j] < 0)	dif[j] += 10;
				if(dif[j])	tot++;
			}	

			if(tot>2 || tot == 0) {
				flag = true;
				break;
			}
			if(tot == 2) {
				for(int j = 1;j <= 5;j++) {
					if(dif[j] != dif[j-1] && dif[j] != dif[j+1]) {
//cout << "---" << g[1] << " " << g[2] << " " << g[3] << " " << g[4] << " " << g[5] << "  |  " << dif[j-1] << " " << dif[j] << " " << dif[j+1] << "  |  " << j << endl;
						flag = true;
						break;
					}
				}
				if(flag)	break;
			}
		}
		if(!flag) {
			ans++;
//cout << g[1] << " " << g[2] << " " << g[3] << " " << g[4] << " " << g[5] << endl;
		} 
	}
	cout << ans << endl;
	return 0;
}