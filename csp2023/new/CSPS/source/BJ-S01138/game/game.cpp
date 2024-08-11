#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 5;
ll n;
char c[N];
string str;
stack<char> st;
ll cnt;
void charge(string s){
	//cout << s << "\n";
	ll len = s.length();
	char tmp;
	for(int i = 0; i < len; i++){
		if(!st.empty()){
			tmp = st.top();
			if(tmp == s[i]){
				st.pop();
				continue;
			}
		}
		st.push(s[i]);
	}
	if(st.empty()){
		cnt++;
		//cout << s << "\n";
	}
	while(!st.empty()){
		st.pop();
	}
	return ;
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld\n", &n);
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		//cout << c[i];
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= n - i + 1; j++){
			for(int k = j; k <= j + i - 1; k++){
				str += c[k];
				//cout << c[k];
			}
			//cout << " ";
			charge(str);
			str = {};
		}
		//cout << endl;
	}
	printf("%lld", cnt);
	return 0;
}
