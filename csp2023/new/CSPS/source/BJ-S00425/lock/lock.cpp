

#include <bits/stdc++.h>

using namespace std;

int n;
int ans;
int situation[10][7];
bool real[10];
int fakecode[10];
int curint = 0;

bool Check(int a){
	bool tc[6];
	memset(tc , 0 , sizeof(tc));
	string str = "";
	str += (char) (a / 10000 + '0');
	str += (char) (a / 1000 % 10 + '0');
	str += (char) (a / 100 % 10 + '0');
	str += (char) (a / 10 % 10 + '0');
	str += (char) (a % 10 + '0');
	int together = 0;
	for(int i = 0; i <= 3; i++){
		if(str[i] == str[i + 1] && str[i] != '0'){
			together ++;
			tc[i] = true;
			tc[i + 1] = true;
		} 
	}
	int single = 0;
	for(int i = 0; i <= 4; i++){
		if(!tc[i] && str[i] != '0'){
			single ++;
		}
	}
	if(single + together == 1){
		return true;
	}
	return false;
}

int main(){
	freopen("lock.in" , "r" , stdin);
	freopen("lock.out", "w" , stdout);
	
	cin >> n;
	for(int i = 1; i <= n ; i++){
		curint = 0;
		for(int j = 1; j <= 5; j ++){
			cin >> situation[i][j];
			curint = curint * 10 + situation[i][j]; 
		}
		fakecode[i] = curint; 
	}
	int number;
	for(int first = 0; first <= 9; first ++){
		for(int second = 0; second <= 9; second ++){
			for(int third = 0; third <= 9; third ++){
				for(int forth = 0; forth <= 9; forth ++){
					for(int fifth = 0; fifth <= 9; fifth ++){
						int res = 0;
						bool flag = true;
						for(int j = 1; j <= n; j++){
							int swa = first;
							int swb = second;
							int swc = third;
							int swd = forth;
							int swe = fifth;
							res = 0;
							while(swa != situation[j][1]){
								swa = (swa + 1) % 10; 
								res += 10000;
							}
							while(swb != situation[j][2]){
								swb = (swb + 1) % 10; 
								res += 1000;
							}
							while(swc != situation[j][3]){
								swc = (swc + 1) % 10; 
								res += 100;
							}
							while(swd != situation[j][4]){
								swd = (swd + 1) % 10; 
								res += 10;
							}
							while(swe != situation[j][5]){
								swe = (swe + 1) % 10; 
								res += 1;
							}
							if(!Check(res)){
								flag = false;
							}
						}
						if(flag){
							ans ++;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
};