

#include <bits/stdc++.h>

using namespace std;

int n , m, k;
struct edge{
	int from;
	int to;
	int worth;
};
int u , v , w;
vector<edge > ma[10009];
int rudu[10009];
queue<int > que;
bool visit[10009];
bool ring = false;
int curval[10009];
int depth[10009];
bool allaz = true;
int res = -1;

void Dfs(int x , int cc){
	if(x == n){
		if(cc % k == 0){
			if(res == -1){
				res = cc;
			}else{
				res = min(cc, res);
			}
		}
		return;
	}
	if(cc >= 100 * n){
		return;
	}
	if(cc >= res && res != -1){
		return;
	}
	for(int i = 0; i < ma[x].size(); i++){
		int y = ma[x][i].to;
		Dfs(y , cc + 1);
	}
	return;
}

int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		edge a;
		a.from = u;
		a.to = v;
		a.worth = w;
		if(w != 0){
			allaz = false;
		}
		ma[u].push_back(a);
		rudu[v] ++;
	}
	
	int dian = 0;
	que.push(1);
	dian ++;
	
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(int i = 0 ; i < ma[x].size(); i++){
			int y = ma[x][i].to;
			rudu[y] --;
			if(rudu[y] == 0){
				que.push(y);
				dian ++;
			}
		}
	}
	
	if(dian != n){
		ring = true;
	}
	
	if(allaz){
		Dfs(1 , 0);
		cout << res << endl;
		return 0;
	}else{
		cout << -1 << endl;
	}
	
	return 0;
}
//first , does it have a ring?
//no -> use Bfs();
/*
queue<int >q;
		q.push(1);
		while(!q.empty()){
			int x = que.front();
			que.pop();
			for(int i = 0; i < ma[x].size(); i++){
				int y = ma[x][i].to;
				int req = ma[x][i].worth;
				depth[y] = depth[x] + 1;
				if(curval[x] < req){
					if((req - depth[x]) % k == 0){
						curval[y] = min(curval[y] , req + 1);
					}else{
						curval[y] = min(curval[y] , (((req - depth[x]) / k) + 1) * k + depth[x] + 1);			
					}					
				...So...That's all..?
				for my entire OI life
				I still don't know how to solve graph problems
				AFOed
				}else{
					curval[y] = min(curval[y] , curval[x] + 1);
				}
				q.push(y);
			}
		}
		cout << curval[n] << endl;
*/