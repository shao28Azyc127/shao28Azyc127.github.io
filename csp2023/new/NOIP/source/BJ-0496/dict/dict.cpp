#include<bits/stdc++.h>
using namespace std;
int n,m;
struct bkt{
	int nm[30]; bool type; int ai;
	bool operator < (const bkt&x) const{
//		return nm[1]>x.nm[1];-
		for(int i=26;i>=1;i--){
			if(nm[i]==x.nm[i]) continue;
			return nm[i]>x.nm[i];
		}
		return nm[1]>x.nm[1];
	}
}a[6000+5];
priority_queue <bkt> q;
bool pd(int i){
	int i0=26, ii=1;
	if(a[0].ai==a[i].ai) return  1;
	while(true){
		if(a[0].nm[i0]==0) i0--;
		else break;
	}
	while(true){
		if(a[i].nm[ii]==0) ii++;
		else break;
	}
//	cout<<' '<<i0<<' '<<ii<<endl;
	if(i0>ii) return 1;
	if(i0<=ii) return 0;
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int  i=1;i<=n;i++){
		a[i].ai=i;
		for(int j=1;j<=m;j++){
			char c; cin>>c;
			a[i].nm[c-'a'+1]++;
		}
	}
	for(int i=1;i<=n;i++){
		q.push(a[i]);
	}
//	cout<<q.top().ai<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<q.top().ai; q.pop();
//		//c//out<<tp.ai;
//	}
	a[0]=q.top();
	for(int i=1;i<=n;i++){
		cout<<pd(i);
	}
//	cout<<(a[1]<a[2]);
	return 0;
}
