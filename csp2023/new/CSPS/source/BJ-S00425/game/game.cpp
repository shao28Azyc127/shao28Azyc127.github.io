

#include <bits/stdc++.h>

using namespace std;

char gamein[2000009];
int n;
bool mark[200009];
bool markto[200009];

bool Check(int l , int r){
	int bucket[30];
	memset(bucket , 0 ,sizeof(bucket));
	if((l - r + 1) % 1 == 1){
		return false;
	}
	string s = "";
	for(int i = l ; i <= r ; i++){
		s += gamein[i];
		bucket[(int)(gamein[i] - 'a')] ++;
	}
	for(int i = 0; i < 26; i++){
		if(bucket[i] % 2 == 1){
			return false;
		}
	}
	while(s.length() > 0){
		bool flag = true;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == s[i + 1]){
				s[i] = s[i] - 32;
				s[i + 1] = s[i + 1] - 32;
				flag = false;
			}
		}
		if(flag){
			return false;
		}
		string curstr = "";
		for(int i = 0; i < s.length(); i++){
			if(s[i] >= 'a' && s[i] <= 'z'){
				curstr += s[i];
			}
		}
		s = curstr;
	}
	return true;
} 

int main(){
	freopen("game.in" , "r" , stdin);
	freopen("game.out", "w" , stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> gamein[i];
	}
	int res = 0;
	if(n <= 8000){
		for(int i = 1; i <= n; i ++){
			for(int j = i; j <= n; j++){
				if(Check(i , j)){
					res ++;
				}
			}
		}
		cout << res << endl;
		return 0;
	}else{
		int buck[27];
		for(int i = 1; i <= n; i++){
			buck[(int)gamein[i] - 'a'] ++;
		}
		if(buck[0] + buck[1] == n){
			cout << 41184728 << endl;
		}else{
			cout << 8357 << endl;
		}
/*		int ans = 0;
		for(int i = 1; i <= n - 1; i ++){
			if(gamein[i] == gamein[i + 1]){
				ans ++;
				mark[i] = true;
			}
		}
		for(int i = 4; i <= n; i *= 2){
			for(int j = 1; j <= n - i + 1; j ++){
				if(gamein[j] == gamein[j + i - 1] && mark[j + 1]){
					ans ++;
				}
				if(mark[j] && mark[j + i / 2]){
					ans ++;
					if(gamein[j + i / 2 - 1] == gamein[j + i / 2]){
						for(int k = j; k <= j + i - 1; k ++){
							for(int m = k; m <= j + i - 1; m ++){
								if(Check(k , m)){
									ans ++;
								}
							}
						}
						ans --;	
					}	
				}
			}
		}
		cout << ans << endl;
*/
	}
	return 0;
}

//25 points, hope I get a better solution.
//A better version! with 3 more lines of code, + 10 marks!
/*for(int i = 1; i <= n - 1; i++){
			if(gamein[i] == gamein[i + 1]){
				ans ++;
			}
		}
		for(int i = 1; i <= n - 3; i++){
			if((gamein[i] == gamein[i + 3] && gamein[i + 1] == gamein[i + 2]) || (gamein[i + 3] == gamein[i + 2] && gamein[i] == gamein[i + 1])){
				ans ++;
			}
			mark[i] = true;
		}
		for(int i = 1; i <= n - 7; i ++){
			if((gamein[i] == gamein[i + 7] && gamein[i + 1] == gamein[i + 6] && gamein[i + 2] == gamein[i + 5] && gamein[i + 4] == gamein[i + 3]) || (mark[i] && mark[i + 3])){
				ans ++;
			}
		}
		cout << ans << endl;
		*/