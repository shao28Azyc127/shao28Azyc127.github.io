#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int neg=1e5+10; //任何大于neg的x，真实数值为-(x-neg)
int fa[N];//fa[i]表示i的值=fa[i]
//if(fa[i]==0 || nfa[i]==0) 值为真或假，不为U
int qufan(int x){
	if(x>=neg) return x-neg;
	else return x+neg;
}
int find(int x,int in){
	if(x==in) return x;
	if(x==fa[x]) return x;
	else return find(fa[x],in);
}
int n,m;
char v;
int t;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>t>>t;
	while(t--){
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=neg;i<=neg+n-1;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>v;
		if(v=='T' || v=='F'){
			int x;
			cin>>x;
			fa[x]=0;
			fa[qufan(x)]=qufan(0);
		}else if(v=='U'){
			int x;
			cin>>x;
			fa[x]=qufan(x);
		}else if(v=='+'){
			int x,y;
			cin>>x>>y;
			if(find(fa[x],x)!=find(fa[y],y) && find(fa[x],x)!=qufan(find(fa[y],y))){
				fa[x]=y;
				fa[qufan(x)]=qufan(y);
			}else fa[x]=y;
		}else if(v=='-'){
			int x,y;
			cin>>x>>y;
			if(find(fa[x],x)!=find(fa[y],y) && find(fa[x],x)!=qufan(find(fa[y],y))) {fa[qufan(x)]=y; fa[x]=qufan(y);}
			else fa[x]=y;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(find(fa[i],i)==find(fa[qufan(i)],qufan(i))) cnt++;
	}
	cout<<cnt<<"\n";
	}
	return 0;
}
