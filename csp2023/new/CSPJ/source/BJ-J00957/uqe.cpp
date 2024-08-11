#include<bits/stdc++.h>
using namespace std;
void chk(int a, int b, int c){
	int s = b * b - 4 * a * c;
	if(s < 0){
		cout << "NO\n";
		return ;
	} 
	double x1 = 1.0 * (-b + sqrt(s)) / (2 * a);
	double x2 = 1.0 * (-b - sqrt(s)) / (2 * a);
	x1 = max(x1, x2);
	if(floor(x1) == ceil(x1)){
		cout << x1 << endl;
		return ;
	}
	
}
int main(){
	freopen("uqe.in", "r", stdin);	
	freopen("uqe.out", "w", stdout);
	int t, m;
	cin >> t >> m;
	while(t --){
		int a, b, c;
		cin >> a >> b >> c;
		chk(a, b, c);
	}
}