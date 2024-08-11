#include <bits/stdc++.h>
using namespace std;
int n,a[10][10],sum[10],ans=0;
bool check(int x){
	for(int i=0; i<n; i++){
		if(a[i][x]-a[i][x+1]!=a[0][x]-a[0][x+1]){
			return 0;
		}
	}
	return 1;
}
int init(int x,int tmp=0){
	for(int i=0; i<n; i++){
		if(a[i][x]!=a[0][x]){
			tmp = tmp + 1;
		}
	}
	return tmp;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<5; i++){
		ans = ans + 9 - init(i);
	}
	for(int i=0; i<4; i++){
		if(check(i)){
			ans = ans + 9 - init(i);
		}
	}
	cout << ans;
	return 0;
}