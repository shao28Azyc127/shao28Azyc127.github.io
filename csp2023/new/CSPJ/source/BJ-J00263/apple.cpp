#include<iostream>
using namespace std;
// #define md1
const int N = 1e6 + 2;
int n;
bool b[N];
int cnt;
int a1, a2;
int next(int a){
	for(int i = a + 1; i <= n; i++){
		if(!b[i]){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	while(cnt < n){
		a1++;
		for(int i = next(0); i;){
			if(i == n){
				a2 = a1;
			}
			b[i] = true;
			cnt++;
			#ifdef md1
			cout << i << ' ';
			#endif
			i = next(i);
			if(i == 0){
				break;
			}
			i = next(i);
			if(i == 0){
				break;
			}
			i = next(i);
		}
		#ifdef md1
		cout << endl;
		#endif
	}
	cout << a1 << " " << a2 << endl;
	return 0;
}