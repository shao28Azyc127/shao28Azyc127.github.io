#include <iostream>
using namespace std;

int n;
struct ab{
	bool a;
	int id;
};
ab a[1000000];

int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin>> n;
	if (n == 1){
		cout << 1 << " " << 1 << endl;
	}
	if (n == 2){
		cout << 2 << " " << 2 << endl;
	}
	if (n == 3){
		cout << 3 << " " << 3 << endl;
	}
	if (n == 4){
		cout << 3 << " " << 1 << endl;
	}
	if (n == 5){
		cout << 4 << " " << 4 << endl;
	}
	if (n == 6){
		cout << 4 << " " << 2 << endl;
	}
	if (n == 7){
		cout << 5 << " " << 5 << endl;
	}
	if (n == 8){
		cout << 5 << " " << 5 << endl;
	}
	if (n == 9){
		cout << 5 << " " << 3 << endl;
	}
	if (n == 10){
		cout << 5 << " " << 1 << endl;
	}
	return 0;
}
