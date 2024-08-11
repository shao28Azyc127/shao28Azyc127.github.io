#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
int val[N]; int c,t;
void c34(){
	int n,m; cin>>n>>m;
	int ans=0;
	for(int i=1;i<=m;i++){
		char opr; int x; cin>>opr>>x;
		if(opr=='U'){
			val[x]=2;
		}
		if(opr=='T'){
			val[x]=1;
		}
		if(opr=='F'){
			val[x]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(val[i]==2) ans++;
	} cout<<ans<<endl;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=100000;i++){
		val[i]=-1;
	}
	if(c==3||c==4){
		while(t--){
			c34();
		}
	}
	
	return 0;
}
