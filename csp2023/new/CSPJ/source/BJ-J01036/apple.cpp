#include <iostream>
using namespace std;

int n;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	int tmp = n,cnt = 0,ans = 0;
	while(tmp){
		cnt++;
		if(tmp % 3 == 2) tmp = tmp / 3 * 2 + 1;
		else tmp = tmp / 3 * 2;
		if(n % 3 == 1) ans = cnt,n = -1;
		if(n % 3 == 0) n = n - n / 3;
		else if(n % 3 == 2) n = n - n / 3 - 1;
	}
	cout << cnt << " " << ans << endl;
	
	return 0;
}//我能吞下身体而不伤玻璃。