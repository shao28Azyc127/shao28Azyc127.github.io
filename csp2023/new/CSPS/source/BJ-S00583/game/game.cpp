#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;
const int N = 2e6 + 7;
int n;
char c[N];
ll ans;

int main(){
	ios::sync_with_stdio(false);
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> c[i];
	}
	for(int i = 1; i <= n; ++i){
		stack <char> s;
		for(int j = i; j <= n; ++j){
			if(s.empty() || s.top() != c[j]){
				s.push(c[j]);
			}else{
				s.pop();
			}
			if(s.empty()){
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}