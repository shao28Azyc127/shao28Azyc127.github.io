#include <iostream>
using namespace std;

int main(){
	int n,days = 0,ans = 0;
	cin >> n;
	while(n > 0){
		days++;
		if (n == 1){
			cout << days << ' ';
			if (ans == 0){
				ans = days;
			}
			cout << ans;
			n--;
		}else{
			n--;
			if (n % 3 == 0){
				if (ans == 0){
					ans = days;
				}
			}
			n -= n / 3;
		}
	}
}