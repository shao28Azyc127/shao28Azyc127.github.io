#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;
long long v[maxn], f[maxn], ff[maxn], sum[maxn];
long long a[maxn], minn[maxn];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for(int i = 1 ; i <= n - 1 ; i++){
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}
	for(int i = 1 ; i <= n ; i++)cin >> a[i];
	long long tmp = a[1];
	minn[1] = 1;
	f[1] = 0;
	for(int i = 2 ; i <= n ; i++){
		if(a[i - 1] >= tmp)minn[i] = minn[i - 1];
		else {
			minn[i] = i - 1;
			tmp = min(tmp, a[i - 1]);
		}
		//cout << minn[i] << tmp <<' ';
	}
	//cout << endl;
	for(int i = 2 ; i <= n ; i++){
		long long aa = minn[i];
		long long vv  = sum[i - 1] - sum[aa - 1];
		if(vv <= ff[aa]){
			f[i] = ff[aa];
			ff[i] = ff[aa] - vv;
		}
		if((vv - ff[aa]) % d != 0){
			f[i] = f[aa] + ((vv - ff[aa]) / d + 1) * a[aa];
			ff[i] = d - (vv - ff[aa]) % d;
		}
		if((vv - ff[aa]) % d == 0){
			f[i] = f[aa] + (vv - ff[aa]) / d * a[aa];
			ff[i] = 0;
		}
	}
	cout << f[n];
	return 0;
}