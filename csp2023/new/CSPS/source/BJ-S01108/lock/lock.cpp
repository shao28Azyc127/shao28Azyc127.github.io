#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N][10];

int lk[10];
int ans;
int n;

int dis(int id, int i){
	return (lk[i]-a[id][i]+10)%10;
}

inline bool ok(int id){
	vector<int> vec;
	vec.clear();
	for(int i=1;i<=5;i++){
		if(lk[i]!=a[id][i]) vec.push_back(i);
	}
	if(vec.size()>=3 || !vec.size()) return 0;
	else if(vec.size()==1) return 1;
	else{
		if(abs(vec[0]-vec[1])>1) return 0;
		if(dis(id, vec[0])==dis(id, vec[1])) return 1;
		else return 0;
	}
	return 1;
}

inline bool check(){
	for(int i=1;i<=n;i++){
		if(!ok(i)) return 0;
	}
	return 1;
}

void dfs(int idx){
	if(idx>5){
		if(check()) ans++;
		return;
	}
	for(int i=0;i<10;i++){
		lk[idx] = i;
		dfs(idx+1);
	}
}

int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin >> a[i][j];
		}
	}
	dfs(1);
	cout << ans << endl;
	
	return 0;
}
