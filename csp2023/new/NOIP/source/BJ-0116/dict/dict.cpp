#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
char s[N][N];
char t[N][N];

int n, m;


int main(){
	ios::sync_with_stdio(0);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		sort(s[i], s[i]+m);
		for(int j=0;j<m;j++){
			t[i][j] = s[i][m-j-1];
		}
	}
	for(int i=1;i<=n;i++){
		bool flag = 1;
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if(strcmp(t[j], s[i])<=0){
				flag = 0;
				break;
			}
		}
		cout << flag;
	}
	cout << endl;
	
	return 0;
}
