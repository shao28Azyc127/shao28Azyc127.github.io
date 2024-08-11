#include <bits/stdc++.h>
using namespace std;
int n,vis[10000000]={1},ans1,ans2;
bool check(){
	for(int i=0; i<n; i++){
		if(vis[i]==1){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("apple.in","r",stdin):
	freopen("apple.out","w",stdout);
	cin >> n;
	while(1){
		ans1 = ans1 + 1;
		for(int i=0; i<n; i++){
			if(vis[i]==1){
				cnt = cnt + 1;
			}
			if(cnt==3){
				vis[i] = 0;
				if(i==n-1){
					ans2 = ans1;
				}
				if(check()){
					cout << ans1 << " " << ans2;
					break();
				}
			}
		}
	}
	return 0;
}
