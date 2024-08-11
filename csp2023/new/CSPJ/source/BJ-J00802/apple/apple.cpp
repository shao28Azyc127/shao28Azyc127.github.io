#include <iostream>

using namespace std;

typedef long long ll;
ll n;

ll Init(ll x){
	if(x <= 0){
		return ll(0);
	}
	if(x % 3 == 0){
		return ll(1) + Init(x - x / 3);
	}else{
		return ll(1) + Init(x - x / 3 - ll(1));
	}
}

ll Find(ll x){
	if(x % 3 == 1){
		return ll(1);
	}else{
		return ll(1) + Find(x - (x - 1) / 3 - ll(1));
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	cout << Init(n) << " " << Find(n) << endl;
	return 0;
}