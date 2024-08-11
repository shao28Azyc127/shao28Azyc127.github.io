#include<bits/stdc++.h>
using namespace std;
int v[100005], a[100005];
int cnt[100005];
int dp[15][1000005];
int main(){
	freopen("road.in", "r", stdin);	
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	int asdf = 0;
	for(int i = 2;i <= n;i ++){
		cin >> v[i];
		asdf += v[i];
		cnt[i] = cnt[i - 1] + v[i];
	}
	int minn = 1e9, minpos;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] < minn){
			minn = a[i];
			minpos = i;
		}
	}
	if(minpos == 1){ 
		cout << asdf / d * a[1];
		return 0;
	}
	long long mon = 0, lastgas = 0;
	int nowpos = 1;
	while(nowpos < n){
		int smallpos = n;
		minn = a[nowpos];
		for(int i = nowpos + 1;i <= n;i ++){
			if(a[i] <= minn){
				smallpos = i;
				break;
			}
		}
		int k = ceil(1.0 * (cnt[smallpos] - cnt[nowpos] - lastgas) / d);
		mon += k * a[nowpos];
		lastgas = k * d - (cnt[smallpos] - cnt[nowpos] - lastgas);
		nowpos = smallpos;
	}
	cout << mon;
}