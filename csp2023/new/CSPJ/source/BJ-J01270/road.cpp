#include<bits/stdc++.h>
using namespace std;
int n,d,ans,l,cnt;
int a[100100];
int v[100100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i = 1; i < n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(v[1] % d == 0){
		ans = a[1] * v[1] / d;
		l = v[1];
	}else{
		ans = a[1] * (v[1] / d + 1);
		l = (v[1] / d + 1) * d;
	}
	//cout << ans << endl;
	for(int i = 1; i < n; i++){
		if(l <= v[i]){
			int k = i + 1;
			while(a[k] > a[i]){
				if((v[k - 1] - l) % d == 0){
					ans += a[i] * (v[k - 1] - l) / d;
					l = v[k - 1];
				}else{
					ans += a[i] * ((v[k - 1] - l) / d + 1);
					l = ((v[k - 1] - l)  / d + 1) * d;
				}
				k++;
				//cout << ans << endl;
			}
			if(l <= v[i]){
				if((v[i] - l) % d == 0){
					ans += a[i] * (v[i] - l) / d;
					l = v[i];
				}else{
					ans += a[i] * ((v[i] - l) / d + 1);
					l += ((v[i] - l) / d + 1) * d;
				}
				//cout << ans << endl;
			}
			l -=v[i];
		}else{
			l -=v[i];
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
