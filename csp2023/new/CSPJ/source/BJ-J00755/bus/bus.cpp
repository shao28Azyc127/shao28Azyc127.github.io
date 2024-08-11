#include<bits/stdc++.h>
#define N 20200
using namespace std;
int n,m,k,ans=0,maxt=INT_MIN,op=INT_MAX;
vector<int> node[N],val[N];
bool flag=0;
void readyp() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,a,b,v;i<=m;i++) {
		scanf("%d%d%d",&a,&b,&v);
		if(v) flag=1;
		maxt=max(v,maxt);
		node[a].push_back(b);
		val[a].push_back(v);
	}
	if(n<20) flag=0;
	return ;
}
int solve2(int mmm) {
	int ans=mmm,tmp;
	queue<pair<int,int> > q;
	q.push(make_pair(1,mmm));
	while(!q.empty()) {
		while(!q.empty()&&q.front().second==ans) {
			tmp=q.front().first;
			if(tmp==n&&ans%k==0) return ans;
			for(int i=0;i<node[tmp].size();i++) if(ans>=val[tmp][i]) {
				q.push(make_pair(node[tmp][i],ans+1));
			}
			q.pop();
		}
		ans++;
	}
	return INT_MAX;
}
int main() {
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	readyp();
	for(int i=0;i<maxt/k+1;i++) op=min(op,solve2(i*k));
	op==INT_MAX?cout<<-1:cout<<op;
	fclose(stdin);
	fclose(stdout);
	return 0;
}