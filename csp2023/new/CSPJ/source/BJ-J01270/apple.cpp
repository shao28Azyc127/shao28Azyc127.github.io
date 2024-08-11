#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,j,ans;
queue<ll> q;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++){
		q.push(i);
	}
	while(!q.empty()){
		j++;
		int cnt = q.size();
		for(ll i = 1; i <= ll(cnt); i++){
			ll a = q.front();
			q.pop();
			if(i % 3 != 1)q.push(a);
			else if(a == n) ans = j;
		}
	}
	cout << j << ' ' << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}