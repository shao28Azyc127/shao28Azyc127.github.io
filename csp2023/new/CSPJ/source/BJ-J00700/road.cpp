#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v, i;
} b[100010];
long long a[100010], vis[100010], s[100010], s1[100010], c[100010];
bool cmp(node x, node y){
	return x.v < y.v;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long ans = 0, n, d;
	cin >> n >> d;
	for (int i = 2; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i].v;
		b[i].i = i;
		c[i] = b[i].v;
	}
	sort(b+1, b+n, cmp);
	for (int i = 1; i <= n; i++){
		long long cnt = 0;
		for (int j = b[i].i + 1; j <= n; j++){
			if (vis[j] == 0){
				vis[j] = b[i].i;
				cnt+=a[j];
			}
		}
		long long tmp = cnt / d;
		if (cnt % d != 0) tmp++;
		//cout << tmp << ' ' << tmp * b[i].v << ' ' << (tmp * d - cnt) << endl;
		s[b[i].i] = (tmp * d - cnt);
		ans += tmp * b[i].v;
	}
	for (int i = 1; i <= n;i++){
		s1[i] = s1[i-1] + s[i];
	}
	for (int i = 1; i <= n;i++){
		if (s1[i] >= d){
			ans -= s1[i] / d * c[i];
			//cout << s1[i] / d * c[i] << ' ';
			long long temp = s1[i] / d * d;
			for (int j = i; j <= n; j++){
				s1[j] -= temp;
			}
		}
	}
	cout << ans;
	return 0;
}