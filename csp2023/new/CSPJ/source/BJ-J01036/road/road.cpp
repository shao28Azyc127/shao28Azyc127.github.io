#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e5;

int n,d,v[maxn + 5],a[maxn + 5];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i = 1;i < n; i++) cin >> a[i];
	for(int i = 1;i <= n; i++) cin >> v[i];
	long long cnt = 0,ans = 0;
	long long o = 0;
	for(int i = 1;i < n; i++){
		cnt += a[i];
		if(v[i+1] < v[i] || i == n - 1){
			int l = cnt - o;
			if(l % d == 0) ans += (l / d) * v[i],o = 0;
			else o = d - l % d,ans += (l/d+1) * v[i];
			cnt = 0;
		}
		else v[i+1] = v[i];
	}
	cout << ans << endl;
	
	return 0;
}
//后方更新法（80分）在程序里，体现的是作用域（和扫描线相关）