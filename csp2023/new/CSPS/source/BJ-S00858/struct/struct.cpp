#include <bits/stdc++.h>
using namespace std;
int n;
string str[100000];long long baddr[100000] , eaddr[100000];
int tot = 0;
int dqum[5] = {0 , 1 , 2 , 4 , 8}; 
long long Upi(long long ins , long long mo) {
	return ins-ins%mo+((ins%mo)?mo:0);
}
int main() { 
	freopen("struct.in" , "r" , stdin);
	freopen("struct.out" , "w" , stdout);
	cin >> n;
	eaddr[0] = -1;
	while(n--) {
		int op;
		cin >> op;
		if(op == 2) {
		tot++;
		string ins;
		cin >> ins;
		int itp;
			cin >>	str[tot];
			if(ins == "byte")	itp = 1 ;
				else if(ins == "short")	itp = 2;
				else if(ins == "int")itp = 3;	
				else if(ins == "long")	itp = 4;
			baddr[tot] = Upi(eaddr[tot-1]+1 , dqum[itp]);
			eaddr[tot] = dqum[itp] + baddr[tot] - 1;
		}
		else if(op == 3) {
			string i21;
			cin >> i21;
			int tmp ;
			for(int i = 1;i <= tot;i++)
				if(str[i] == i21)
					tmp  =i;
					
			cout << baddr[tmp] << endl;
		}
		else {
			long long ir;
			cin >> ir;
			int tmp12 = -1;
			for(int i = 1;i <= tot;i++) {
				if(baddr[i] <= ir && ir <= eaddr[i])
					tmp12  =i;
			}
			if(tmp12 == -1)
				cout << "ERR" << endl;
			else
				cout << str[tmp12] << endl;
		}
	}
	return 0;
}