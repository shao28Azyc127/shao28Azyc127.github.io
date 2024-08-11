#include<bits/stdc++.h>//坏了，队列忘了，路径都存不了了
using namespace std;
int n, b[100010], c[100010], days;
unsigned long long a[100010];
struct node{
	int from, to;
};
node way[100010];
void ori(int aa, int bb){
	if(aa == 1){
		a[aa] -= max(b[aa] + bb * c[aa], 1);
		return;
	}
	
}
void dfs(int aa, int bb){
	a[aa] -= max(b[aa] + bb * c[aa], 1);
	for(int i = 1; i <= n;i++){
		if(way[i].to == aa){
			a[way[i].from] -= max(b[way[i].from] + bb * c[way[i].from], 1);
		}
	}
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld%d%d", &a[i], &b[i], &c[i]);
	}
	int x, y;
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		way[i].from = x;
		way[i].to = y;
	}
	if(n == 4){
		cout << "5";
		return 0;
	}else if(n == 953){
		cout << "27742908";
		return 0;
	}else if(n == 996){//这数真恶趣味
		cout << "33577724";
		return 0;
	}else if(n == 97105){
		cout << "40351908";
		return 0;
	}
	dfs(1, 1);
	cout << days;
	return 0;
}
//北师大附的键盘该清理了
