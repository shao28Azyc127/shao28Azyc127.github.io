#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, t;
int a[1010][4];

int gcd(int x, int y){
	for (int i = max(x, y); i >= 1; i++){
		if (!(x % i) && !(y & i)){
			return i;
		}
	} 
}

int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> n >> t;
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	for(int i = 1; i <= n; i++){
		if (a[i][2] * a[i][2] - 4 * a[i][1] * a[i][3] < 0){
			cout << "NO" << endl;
			continue;
		}
	}
	return 0;
} 
