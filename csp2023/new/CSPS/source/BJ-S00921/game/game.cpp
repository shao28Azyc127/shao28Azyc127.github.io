#include <cstdio>
#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int n, idx;
long long res;
string str;

bool check(int l, int r){
	stack<char> stk;
	for(int i = l; i <= r; ++i){
		if(!stk.empty() && stk.top() == str[i]) stk.pop();
		else stk.push(str[i]);
	}
	return stk.empty();
}

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &n);
	cin >> str;
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			if(check(i, j))
				++res;
	printf("%lld\n", res);
	
	return 0;
}
