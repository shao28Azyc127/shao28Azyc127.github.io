#include<bits/stdc++.h>
using namespace std;
const int NR=3005;
int n,m;
struct word{
	string s,mns,mxs;
	int id;
}w[NR];
struct node{string s;int id;}sw[NR];
bool cmp(node x,node y){
	return x.s<y.s;
}
int id[NR];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>w[i].s,w[i].id=i;
	if(n==1){cout<<1<<endl;return 0;}
	for(int i=1;i<=n;++i){
		w[i].mns=w[i].s;
		sort(w[i].mns.begin(),w[i].mns.end());
		w[i].mxs=w[i].s;
		for(int j=m-1;j>=0;--j)
			w[i].mxs[m-j-1]=w[i].mns[j];
	}
	for(int i=1;i<=n;++i)
		sw[i].s=w[i].mxs,sw[i].id=i;
	sort(sw+1,sw+n+1,cmp);
	for(int i=1;i<=n;++i)id[sw[i].id]=i;
	for(int i=1;i<=n;++i)
		if(w[i].mns<sw[1].s||i==sw[1].id)cout<<1;
		else cout<<0;
	return 0;
}