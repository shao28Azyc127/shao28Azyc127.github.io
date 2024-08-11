#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
string str[3005], minstr = "z";
ll miny;

string xstr[3005], dstr[3005];
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int nm = 1; nm <= n; nm++){
		cin >> str[nm];
	}
	if(n == 1){
		printf("1");
	} else if(m == 1){
		for(int i = 1; i <= n; i++){
			if(str[i] < minstr){
				minstr = str[i];
				miny = i;
				//cout << miny << " " << minstr << "\n";
			}
		}
		for(int i = 1; i <= n; i++){
			if(str[i] == minstr && i != miny){
				miny = -1;
				break;
			}
		}
		if(miny == -1){
			for(int i = 1; i <= n; i++){
				printf("0");
			}
		} else {
			for(int i = 1; i <= n; i++){
				if(i == miny){
					printf("1");
					continue;
				}
				printf("0");
			}
		}
	} else if(m == 2){
		for(int i = 1; i <= n; i++){
			if(str[i][0] >= str[i][1]){
				dstr[i] = str[i];
				xstr[i] += str[i][1];
				xstr[i] += str[i][0];
				//cout << str[i] << " " << xstr[i] << " " << dstr[i] << endl;
			} else if(str[i][0] < str[i][1]){
				xstr[i] = str[i];
				dstr[i] += str[i][1];
				dstr[i] += str[i][0];
				//cout << str[i] << " " << xstr[i] << " " << dstr[i] << endl;
			}
		}
		bool iif = false;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i != j){
					if(xstr[i] >= dstr[j]){
						iif = true;
						break;
					}
				}
			}
			if(iif == false){
				printf("1");
			} else {
				printf("0");
			}
			iif = false;
		}
	}
	return 0;
}
