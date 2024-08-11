#include <iostream>
using namespace std;

int n, cnt = 0;
char ch[100010];

bool zichuan(int x, int y){
	for (int i = x; i <= y; i++){
		if (ch[i] != ch[y - i + 1]){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> ch[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if(zichuan(i, j) == true){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
