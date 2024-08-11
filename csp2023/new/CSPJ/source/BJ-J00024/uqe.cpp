#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t, m;
	cin >> t >> m;
	for(int i = 0; i < t; i++){
		int a,b,c;
		cin >> a >> b >> c;
		double panduan = b * b - 4 * a * c;
		if(panduan < 0) {
			cout << "NO" << endl;
			break;
		}
		double x, y;
		x = (sqrt(panduan) - b) / 2 / a;
		y = (0 - sqrt(panduan) - b) / 2 / a;
		bool plus;
		if (x >= y) plus = true;
		else {
			plus = false;
			x = y;
		}
		
		int temp = x;
		if (x == temp){
			cout << x;
			continue;
		}
		
		bool pd;
		temp = sqrt(panduan);
		if(temp==sqrt(panduan)){
			pd=true;
		}
		else{
			pd=false;
		}
		if(b!=0)
		{
			if(b%(2*a)==0) cout<< (0-b)/2/a;
			else cout << (0-b) << '/' << (2*a);
		}
		if(panduan!=0)
		{
			if(plus==true) cout << "+";
			else cout << "-";
			if(pd==true) cout<<sqrt(panduan);
			else cout << "sqrt(" <<panduan<<")";
		cout << "/" << 2*a;
		}
		cout << endl;
	}
	return 0;
}
