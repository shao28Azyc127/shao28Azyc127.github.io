#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	long long n , m , a , b , c;
	cin >> n >>m;
	for(int i = 1 ; i <=n  ; i++){
		cin >> a>> b >> c;
		if(b==0&&c==0){
			cout << 0 <<endl;
		}
		else{
			cout << "NO";
		}
	}
	return 0;
}
