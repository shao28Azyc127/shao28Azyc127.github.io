

#include <bits/stdc++.h>

using namespace std;

int n;
string dic[3009];
string smal[3009];
string larg[3009];
int bucket[29];
int m;

string insrt(char a , int b){
	string ret = "";
	string zm = "";
	zm += a;
	while(b > 0){
		if(b % 2 == 1){
			ret += zm;
		}
		zm += zm;
		b /= 2;
	}
	return ret;
}

int main(){
	freopen("dict.in" , "r" , stdin);
	freopen("dict.out", "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> dic[i];
		memset(bucket , 0 , sizeof(bucket));
		for(int j = 0; j < m; j++){
			bucket[(int)(dic[i][j] - 'a')] ++;
		}
		string minim = "";
		string maxim = "";
		for(int j = 0; j < 26; j ++){
			if(bucket[j] != 0){
				minim += insrt((char)(j + 'a') , bucket[j]);
			}
		}
		for(int j = 25; j >= 0; j --){
			if(bucket[j] != 0){
				maxim += insrt((char)(j + 'a') , bucket[j]);
			}
		}
		smal[i] = minim;
		larg[i] = maxim;
	}
		
	for(int i = 1; i <= n; i++){
		bool flag = true;
		for(int j = 1; j <= n; j++){
			if(i == j){
				continue;
			}
			if(smal[i] > larg[j]){
				flag = false;
			}
		}
		cout << flag;
	}
	return 0;
}

//my first NOIP
//I don't know how to use diff hellllp me