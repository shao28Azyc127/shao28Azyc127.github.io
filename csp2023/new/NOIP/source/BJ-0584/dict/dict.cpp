#include<iostream>
#include<algorithm>
using namespace std;

char a[3005][3005];


int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for(int i = 1; i<= n; i++){
		for(int j = 1; j<=m; j++){
			cin>>a[i][j];
		}
		std::sort(a[i], a[i]+m+1);
	}
	for(int i = 1; i<=n; i++){
		bool ok = true;
		for(int j = 1; j<=n; j++){
			if(j==i) continue;
			bool flag = true;
			for(int k = 1; k<=m; k++){
				if(a[j][m-k+1]>a[i][k]) break;
				if(a[j][m-k+1]<a[i][k]){
					flag = false;
//					cout<<i<<' '<<j<<' '<<k<<','<<endl;
					break;
				}
				if(k==m&&a[j][m-k+1] == a[i][k]){
					flag = false;
				}
			}
			if(!flag) {
				ok = false;
				break;
			}
		}
		if(ok){
			cout<<'1';
		}
		else cout<<'0';
	}
	cout<<endl;
//	for(int i = 1; i<=n; i++) cout<<1+a[i]<<endl;
	return 0;
}
