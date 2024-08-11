#include<iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e5 + 10;
vector <int>v[maxn];
bool t[maxn];
int f[maxn], n, m, k;
int bfs(){
	queue<int>q;
	q.push(1);
	f[1] = 1;
	while(q.size()){
		int x = q.front();
		q.pop();
		for(auto w : v[x]){
			if(!t[w]){
				t[w] = true;
				f[w] = f[x] + 1;
				q.push(w);
			}
		}
	}
	return f[n];
}
int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i =1 ; i<= m ; i++){
		int a, b;
		cin >> a >> b >> k;
		v[a].push_back(b);
	}
	cout << bfs();
	return 0;
}
