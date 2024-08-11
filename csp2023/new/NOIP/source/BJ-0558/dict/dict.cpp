#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
namespace Solve1{
	int minn = 26;
	char a[3005][3005];
	void work(){
		for(int i = 1; i <= n; i++){
			scanf("%s", a[i] + 1);
		}
		for(int i = 1; i <= n; i++)
			minn = min(minn, a[i][1] - 'a');
		for(int i = 1; i <= n; i++)
			if(a[i][1] - 'a' == minn)
				printf("1");
			else
				printf("0");
		return;
	}
}
namespace Solve2{
	struct node {
		string s;
		int id;
		int book[26];
		friend bool operator < (node a, node b){
			for(int i = 25; i > 0; i--){
				if(a.book[i] != b.book[i])
					return a.book[i] < b.book[i];
			}
			return a.book[0] < b.book[0];
		}
	}a[3005];
	bool cmp(node a, node b){
		int c[3005], d[3005], tot1 = 0, tot2 = 0;
		for(int i = 0; i <= 25; i++){
			int x = a.book[i];
			while(x--) c[++tot1] = i;
		}
		for(int i = 25; i >= 0; i--){
			int x = b.book[i];
			while(x--) d[++tot2] = i;
		}
		for(int i = 1; i <= n; i++){
			if(c[i] < d[i]) return true;
			if(c[i] > d[i]) return false;
		}
		return false;
	}
	void work(){
		for(int i = 1; i <= n; i++){
			cin >> a[i].s;
			a[i].id = i;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < m; j++){
				a[i].book[a[i].s[j] - 'a']++;
			}
		}
		int mn = 1;
		for(int i = 1; i <= n; i++){
			if(a[i] < a[mn]){
				mn = i;
			}
		}
		int flag = 1;
		for(int i = 1; i <= n; i++){
			if((i != mn) && !(a[i] < a[mn]) && !(a[mn] < a[i])) flag = 0;
		}
		for(int i = 1; i <= n; i++){
			if(i == mn && flag){
				printf("1");
				continue;
			}
			if(cmp(a[i], a[mn]))
				printf("1");
			else
				printf("0");
		}

	}
}
int main () {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if(n <= 1){
		printf("1");
		return 0;
	}
	if(m <= 1){
		Solve1::work();
		return 0;
	}
	Solve2::work();
	return 0;
}