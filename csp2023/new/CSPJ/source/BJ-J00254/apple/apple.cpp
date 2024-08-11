#include <bits/stdc++.h>
using namespace std;
bool t[1000010];
int a = 1, b;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, a = 1;
	cin >> n;
	if((n - 1) % 3 == 0){
		while(n){
			n -= (n - 1) / 3 + 1;
			a++;
		}
		cout << a - 1 << ' ' << 1;
		return 0;
	}
	if(n <= 1000000){
		int tmp =n;
		while(n > 0){
			int cnt = 3;
			for(int i = 1 ; i <= tmp; i ++)if(!t[i]){
				cnt++;
				//cout << cnt << ' ';
				if(cnt == 4){
					t[i] = true;
					cnt = 1;
					n--;
					if(i == tmp)b = a;
				}
			}
			a++;
			//cout << endl;
		}
		cout << a - 1 << ' ' << b;
		return 0;
	}
	
}