#include<iostream>
#include<vector>
using namespace std;
const int N = 8002;
int n;
long long ans;
int a[N];
bool dp[N][N];
vector<int> v[N];
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;
		a[i] = c - 'a' + 1;
	}
	for(int l = 2; l <= n; l += 2){
		for(int i = 1, j = i + l - 1; j <= n; i++, j++){
			dp[i][j] = (a[i] == a[j]);
			if(l != 2){
				dp[i][j] &= dp[i + 1][j - 1];
			}
			for(int k : v[i]){
				if(dp[i][j]){
					break;
				}
				dp[i][j] = dp[i][k] && dp[k + 1][j];
			}
			ans += dp[i][j];
			if(dp[i][j]){
				v[i].push_back(j);
			}
		}
	}
	cout << ans << endl;
}
/*
#include<hashtable.h>
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
const int n = 8000;
int main(int num, char *strs[]){
	freopen("game.in", "w", stdout);
	string s = strs[1];
	size_t ha = hash<string>{}(s);
	int a = ha;
	srand(a);
	cout << n << endl;
	for(int i = 1; i <= n; i++){
		cout << (char)(rand() % 26 + 'a');
	}
	cout << endl;
}
*/