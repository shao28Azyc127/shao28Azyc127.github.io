#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e6+5, N1 = 8000+5, B = 30, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int n, pre[N];
string s;
#define FILE "game"
int main(){
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	s = '*'+s;
	int ans = 0;
	for(int l = 1; l <= n; l++){
		for(int r = l+1; r <= n; r += 2){
			vector<char> q;
			for(int i = l; i <= r; i++){
				if(!q.empty() && q.back() == s[i]) q.pop_back();
				else q.push_back(s[i]);
			}
			if(q.empty()) ans++;
		}
	}
	cout<<ans;
	return 0;
}
