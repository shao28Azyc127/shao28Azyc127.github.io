#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n;
bool vis[1000005];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	int nn = n;
	int tian = 0;
	while(nn){
		nn -= 1;
		int shu = nn/3;
		nn = nn % 3;
		nn += shu*2;
		tian++;
		
	}
	cout << tian;
	for(int i = 1;i <= tian;i++){
		int shuliang = 0;
		for(int j = 1;j <= n;j++){
			if(vis[j]) continue;
			if(shuliang%3 == 0){
				vis[j] = true;
				if(j == n){
					cout << " " << i;
					return 0;
				}
			}
			shuliang++;
		}
	}	
	
}