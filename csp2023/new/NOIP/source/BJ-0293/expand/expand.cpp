#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int Tid,n,m,q,a[N],b[N],orga[N],orgb[N],k1,k2,x,y;
int la[N],lb[N];
int subtask1(){
	if(n==1&&m==1)	return a[1]!=b[1];
	else if(n<=2&&m<=2){
		if(n==2&&m==2){
			if(max(a[1],a[2])<min(b[1],b[2]))	return 1;
			else if(max(b[1],b[2])<min(a[1],a[2]))	return 1;
			return 0;
		}else if(n==2){
			if(a[1]<=b[1]&&b[1]<=a[2])	return 0;
			return 1;
		}else if(m==2){
			if(b[1]<=a[1]&&a[1]<=b[2])	return 0;
			return 1;
		}
	}
	return 1;
}
int subtask2(){
	unordered_set<int> s;
	for(int i=1;i<=n;i++)	s.insert(a[i]);
	for(int i=1;i<=m;i++)	if(s.count(b[i]))	return 0;
	return 1;
}
int solve(){
	if(Tid<=8)	return subtask1();
	else	return subtask2();
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Tid>>n>>m>>q;
	for(int i=1;i<=n;i++)   cin>>orga[i];
	for(int i=1;i<=m;i++)   cin>>orgb[i];
	memcpy(a,orga,sizeof(a)),memcpy(b,orgb,sizeof(b));
	cout<<solve();
	while(q--){
		cin>>k1>>k2;
		memcpy(a,orga,sizeof(a)),memcpy(b,orgb,sizeof(b));
		while(k1--) cin>>x>>y,a[x]=y;
		while(k2--) cin>>x>>y,b[x]=y;
		cout<<solve();
	}
	cout<<'\n';
	return 0;
}
