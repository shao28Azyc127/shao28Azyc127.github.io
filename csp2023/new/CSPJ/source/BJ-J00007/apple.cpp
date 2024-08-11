#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
typedef long long ll;
using namespace std;
ll h[1000003];
ll hh[1000003];
bool vis[1000003];

int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	ll n;
	cin >> n;
	ll tmp = n, cnt = 0;
	while(tmp){
		if(tmp % 3 == 0){
			tmp -= (tmp / 3);
		}else{
			tmp -= (tmp / 3 + 1);
		}
		++cnt;
	}
	cout << cnt << ' ';
	for(ll i = 1; i <= n; ++i){
		h[i] = i;
	}
	cnt = 0;
	ll live = n;
	ll index = 0;
	ll timee = 0;
	while(live){
		timee++;
		index = 0;
		for(ll i = 1; i <= live; ++i){
			if(i % 4 != 1){
				hh[++index] = h[i];
			}else{
				if(h[i] == n){
					cout << timee - 1 << endl;
					exit(0);
				}
			}
		}
		live = index;
		for(ll i = 1; i <= live; ++i){
			h[i] = hh[i];
			hh[i] = 0;
		}
	}
	return 0;
}
