//CSP2023 RP++ !!!!
#include <iostream>
#define int long long
using namespace std;
int numEdge = 0;
struct node{
	int to;
	int next;
	int w;
}e[200010];
int head[200010];
void AddEdge(int u, int v, int w){
	numEdge ++;
	e[numEdge].next = head[u];
	e[numEdge].to = v;
	e[numEdge].w = w;
	head[u] = numEdge;
}
int n = 0;
int a[200010];
int b[200010];
int c[200010];
inline int read(){
	char ch = getchar();
	int x = 0;
	int f = 1;
	while(ch < '0'||ch>'9'){
		if(ch=='-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >='0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int lst[200010];
bool check(){
	for(int i = 1; i <= n; i++){
		if(lst[i] < a[i]){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		b[i] = read();
		c[i] = read();
	}	
	bool flg = true;
	for(int i = 1; i < n; i++){
		int u = read();
		int v = read();
		if(v != u + 1 && v != u - 1){
			flg = false;
		}
		AddEdge(u, v, 0);
		AddEdge(v, u, 0);
	}	
	if(!flg){
		cout << n + 1;
		return 0;
	}
	if(flg){
		int cnt = 1;
		int now = 1;
		int fa = 0;
		int nxt = 0;
		while(cnt <= n){
			for(int i = head[now]; i; i = e[i].next){
				if(e[i].to != fa){
					nxt = e[i].to;
					break;
				}
			}
			for(int i = cnt; i <= n; i++){
				lst[now] = lst[now] + max(b[now] + i * c[now], 1ll);
			}
			fa = now;
			now = nxt;
			cnt ++;
			 
		}
		if(!check()){
			while(!check){
				for(int i = 1; i <= n; i++){
					lst[i] += max(b[i] + cnt * c[i], 1ll);
				}
				cnt ++;
			}
			cout << cnt - 1;
			return 0;
		}
		else{
			cout << n;
			return 0;
		}
	}
}
//CSP2023 RP++ !!!!