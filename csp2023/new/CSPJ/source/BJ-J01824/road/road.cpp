#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n = 0, d = 0;
	cin >> n >> d;
	int sum = 0;
	int v[100005], a[100005];
	for(int i = 0; i < n - 1; i++){
		cin >> v[i];
		sum += v[i];
	}
	cin >> a[0];
	int min = a[0];
	for(int i = 1; i < n; i++){
		cin >> a[i];
		if(a[i] < min){
			min = a[i];
		}
	}
	int ans = ceil(sum / d) * min;
	cout << ans << endl;
	
	return 0;
}
