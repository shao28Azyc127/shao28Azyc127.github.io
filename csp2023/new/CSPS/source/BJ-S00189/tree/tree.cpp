#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a,b,c,aa,bb,cc;
	for(int i = 1;i <= n;i++){
		if(i == 1) cin >> a >> b >> c;
		cin >> aa >> bb >> cc;
	}
	for(int i = 1;i < n;i++){
		cin >> aa >> bb;
	}

	int i;
	for(i = 1;a > 0;i++){
		a -= max(b + i * c,1);
	}

	cout << i;
}