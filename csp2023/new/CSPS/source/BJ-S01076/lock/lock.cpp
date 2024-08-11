#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 10, P = 1e5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int n;
bool vis[N][P]; // 00000 ~ 99999
const int pos[6] = {0, 10000, 1000, 100, 10, 1};
#define FILE "lock"
int main(){
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int x[6], st;
	for(int i = 1; i <= n; i++){
		st = 0;
		for(int j = 1; j <= 5; j++){
			cin>>x[j];
			st = st*10+x[j];
		}
		for(int p = 1; p <= 5; p++){
			for(int k = 1; k <= 9; k++){
				int cur = st-x[p]*pos[p]+(x[p]+k)%10*pos[p];
				vis[i][cur] = 1;
			}
		}
		for(int p = 1; p < 5; p++){
			for(int k = 1; k <= 9; k++){
				int cur = st-x[p]*pos[p]-x[p+1]*pos[p+1]
						 +(x[p]+k)%10*pos[p]+(x[p+1]+k)%10*pos[p+1];
				vis[i][cur] = 1;
			}
		}
	}
	int cnt = 0;
	bool f;
	for(int st = 0; st < P; st++){
		f = 1;
		for(int i = 1; i <= n; i++) f = (f && vis[i][st]);
		cnt += f;
	}
	cout<<cnt<<endl;
	return 0;
}
