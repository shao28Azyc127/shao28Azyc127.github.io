

#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int curn;
int Rks;
int TaKe = 3333333333;

signed main(){
	freopen("apple.in" , "r" , stdin);
	freopen("apple.out" , "w" , stdout);
	
	cin >> n;
	curn = n;
	while(curn > 0){
		if(curn % 3 == 1){
			TaKe = min(TaKe , Rks + 1);
		}
		if(curn % 3 >= 1){
			curn -= curn / 3 + 1;
			Rks ++;
			
		}else{
			curn -= curn / 3;
			Rks ++;
		}
	}
	if(n == 0){
		cout << 0 << ' ' << 0 << endl;
		return 0;
	}
	cout << Rks << ' ' << TaKe;
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
% 3 = 1
2 3 5 6 8 9 11 12 14 15 

2 6 11 15
Ta Ke!
*/