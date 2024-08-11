#include <iostream>
using namespace std;

int n,d,len;
int v[100005],a[100005];
int path[100005],dist[100005];

int ma(int a,int b){
	int ans = a / b;
	if (b * ans < a){
		ans++;
	}
	return ans;
}

int main(){
	len = 0;
	int ans = 0,dis = 0;
	cin >> n >> d;
	for (int i = 0;i < n - 1;i++){
		cin >> v[i];
	}
	for (int i = 0,min = 9999999;i < n;i++){
		cin >> a[i];
		if (a[i] < min || (i == n - 1)){
			min = a[i];
			path[len] = i;
			if (len > 0){
				dist[len] = dis;
			}
			dis = 0;
			len++;
		}
		if (i < n - 1){
			dis += v[i];
		}
	}
	for (int i = 1,plenty = 0,buyV = 0;i < len;i++){
		if (plenty >= dist[i]){
			plenty -= dist[i];
		}else{
			buyV = ma(dist[i] - plenty,d);
			plenty += d * buyV - dist[i];
			ans += a[path[i - 1]] * buyV;
		}
	}
	cout << ans;
	return 0;
}