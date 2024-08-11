#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int W = 30;
const int N = 3007;
int n, m;
int cnt[W];
string str, minn[N];

struct Node{
	int id;
	string a;
	bool operator<(const Node & no)const{
		return a < no.a;
	}
}maxn[N];

void Insert(int id, string s){
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= m; ++i){
		cnt[s[i - 1] - 'a']++;
	}
	maxn[id].id = id;
	maxn[id].a = "";
	for(int i = 25; i >= 0; --i){
		for(int j = 1; j <= cnt[i]; ++j){
			maxn[id].a += char(i + 'a');
		}
	}
	minn[id] = "";
	for(int i = 0; i <= 25; ++i){
		for(int j = 1; j <= cnt[i]; ++j){
			minn[id] += char(i + 'a');
		}
	} 
}

int main(){
	ios::sync_with_stdio(false);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	if(n == 1){
		cout << "1";
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		cin >> str;
		Insert(i, str);
	}
	sort(maxn + 1, maxn + n + 1);
	for(int i = 1; i <= n; ++i){
		int tmp = 1;
		if(maxn[tmp].id == i) tmp++;
		if(maxn[tmp].a <= minn[i]){
			cout << "0";
		}else{
			cout << "1";
		}
	}
	cout << endl;
	return 0;
}	