#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int c,T,n,m;
struct EXPRESS{
	int id,k,con; // id=0 -> con  else X[id]*k
}a[100005];
int ans[100005];
set<int> eqs;
void build(int val){
	for(int x:eqs){
//		cout<<x<<" "<<val<<endl;
		if(x<0) ans[-x]=-val;
		if(x>0) ans[x]=val;
	}
//	cout<<"kong"<<endl;
	eqs.clear();
}
void find(int i,int k){
	if(a[i].id==0){
		build(a[i].con*k);
		return;
	}
	if(ans[a[i].id]!=-2){
		build(ans[a[i].id]*k*a[i].k);
		return;
	}
	if(eqs.count(a[i].id)==1){
		if(a[i].k*k==-1){
			build(0);
			return;
		}else{
			build(1);
			return;
		}
	}
	if(eqs.count(-a[i].id)==1){
		if(a[i].k*k==1){
			build(0);
			return;
		}else{
			build(1);
			return;
		}
	}
	eqs.insert(k*a[i].k*a[i].id);
	find(a[i].id,k*a[i].k);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		eqs.clear();
		for(int i=1;i<=n;i++){
			a[i].id=i;
			a[i].k=1;
			a[i].con=0;
		}
		for(int i=1;i<=m;i++){
			char v;
			cin>>v;
			if(v=='T'){
				int i;
				cin>>i;
				a[i].id=0;
				a[i].con=1;
			}
			if(v=='F'){
				int i;
				cin>>i;
				a[i].id=0;
				a[i].con=-1;
			}
			if(v=='U'){
				int i;
				cin>>i;
				a[i].id=0;
				a[i].con=0;
			}
			if(v=='+'){
				int i,j;
				cin>>i>>j;
				a[i]=a[j];
			}
			if(v=='-'){
				int i,j;
				cin>>i>>j;
				a[i]=a[j];
				if(a[i].id==0) a[i].con=-a[i].con;
				else a[i].k=-a[i].k;
			}
		}
		/*for(int i=1;i<=n;i++){
			if(a[i].id==0) cout<<a[i].con<<endl;
			else cout<<a[i].k<<"x"<<a[i].id<<endl;
		}*/
		//build
		for(int i=1;i<=n;i++) ans[i]=-2;
		for(int i=1;i<=n;i++){
			if(ans[i]==-2) {
				eqs.insert(i);
				find(i,1);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++) if(ans[i]==0) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
