#include <iostream>

using namespace std;

const int N = 5e5 + 7;
int n, m, q;
int a[N], b[N], px[N], vx[N], py[N], vy[N];

int main(){
	ios::sync_with_stdio(false);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int C;
	cin >> C >> n >> m >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= m; ++i) cin >> b[i];
	if(n == 1 && m == 1){
		if(a[1] == b[1]){
			cout << "0";
		}else{
			cout << "1";
		}
	}else if(n == 1 && m == 2){
		if(a[1] < b[1] && a[1] < b[2]){
			cout << "1";
		}else if(a[1] > b[1] && a[1] > b[2]){
			cout << "1";
		}else{
			cout << "0";
		}
	}else if(n == 2 && m == 1){
		if(a[1] < b[1] && a[2] < b[1]){
			cout << "1";
		}else if(a[1] > b[1] && a[2] > b[1]){
			cout << "1";
		}else{
			cout << "0";
		}
	}else if(n == 2 && m == 2){
		if(a[1] < b[1] && a[2] < b[2]){
			cout << "1";
		}else if(a[1] > b[1] && a[2] > b[2]){
			cout << "1";
		}else{
			cout << "0";
		}
	}else{
		cout << "0";
	}
	while(q--){
		int kx, ky;
		cin >> kx >> ky;
		for(int i = 1; i <= kx; ++i){
			int tmp;
			cin >> px[i] >> tmp;
			vx[i] = a[px[i]]; 
			a[px[i]] = tmp;
		}
		for(int i = 1; i <= ky; ++i){
			int tmp;
			cin >> py[i] >> tmp;
			vy[i] = b[py[i]];
			b[py[i]] = tmp;
		}
		if(n == 1 && m == 1){
			if(a[1] == b[1]){
				cout << "0";
			}else{
				cout << "1";
			}
		}else if(n == 1 && m == 2){
			if(a[1] < b[1] && a[1] < b[2]){
				cout << "1";
			}else if(a[1] > b[1] && a[1] > b[2]){
				cout << "1";
			}else{
				cout << "0";
			}
		}else if(n == 2 && m == 1){
			if(a[1] < b[1] && a[2] < b[1]){
				cout << "1";
			}else if(a[1] > b[1] && a[2] > b[1]){
				cout << "1";
			}else{
				cout << "0";
			}
		}else if(n == 2 && m == 2){
			if(a[1] < b[1] && a[2] < b[2]){
				cout << "1";
			}else if(a[1] > b[1] && a[2] > b[2]){
				cout << "1";
			}else{
				cout << "0";
			}
		}else{
			cout << "0";
		}
		for(int i = 1; i <= kx; ++i){
			a[px[i]] = vx[i];
		}
		for(int i = 1; i <= ky; ++i){
			b[py[i]] = vy[i];
		}
	}
	return 0;
}	