#include<bits/stdc++.h>
using namespace std;
int st[15][15];
int dis(int x,int y){
	if(x < y)return y - x;
	return y + 10 - x;
}
bool match(int a[],int b[]){
	int num = 0,s = 0,p = 0;
	for(int i = 1;i <= 5;i++)
		if(a[i] != b[i]){
			if(num == 0){
				num++;
				s = dis(a[i],b[i]);
				p = i;
			}
			else if(num == 1){
				if(i != p + 1)return false;
				if(dis(a[i],b[i]) != s)return false;
				num++;	
			}
			else return false;
		}
	return (num == 1 || num == 2);
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= 5;j++)cin >> st[i][j];
	int ans = 0;
	for(int i = 0;i <= 99999;i++){
		int t = i;int cur[15];
		for(int j = 1;j <= 5;j++){cur[j] = t % 10;t /= 10;}
		int mat = 0;
		for(int j = 1;j <= n;j++)
			if(match(cur,st[j]))mat++;
		if(mat == n)ans++;
	}
	cout << ans << '\n';
	return 0;
}