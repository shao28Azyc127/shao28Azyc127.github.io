#include<bits/stdc++.h>
using namespace std;
const int N=500000+5;
int c,n,m,q;  int an,am;
int na[N],nb[N];
int a[N],b[N];
bool dp[2005][2005];
void pd(){
//	cout<<an<<' '<<am<<' ';
	for(int i=0;i<=2000;i++){
		for(int j=0;j<=2000;j++){
			dp[i][j]=0;
		}
	}
	if(a[1]==b[1]) {cout<<0; return ;}
	dp[1][1]=1;
	for(int s=3;s<=an+am;s++){
		for(int i=max(1,s-am);i<=min(s-1,an);i++){
			int j=s-i;
//			cout<<i<<' '<<j;
			if(a[i]<b[j]){
				dp[i][j]|=(dp[i-1][j]||dp[i][j-1]);
			}// cout<<"  "<<dp[i-1][j]<<' '<<dp[i][j-1]<<' '<<dp[i][j]<<endl;
		}
	}
	cout<<dp[an][am];
	return ;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>na[i];
	}
	for(int i=1;i<=m;i++){
		cin>>nb[i];
	}
	for(int i=1;i<=n;i++){
			a[i]=na[i]; 
	}
	for(int i=1;i<=m;i++){
		b[i]=nb[i];
	}
	an=n,am=m;
	if(a[1]>b[1]){
	//	cout<<'!';
		swap(an,am);
		for(int i=1;i<=max(n,m);i++){
			swap(a[i],b[i]);
			
		}
	//	cout<<a[1];
	}
	pd();
	while(q--){
		an=n,am=m;
		for(int i=1;i<=n;i++){
			a[i]=na[i]; 
		}
		for(int i=1;i<=m;i++){
			b[i]=nb[i];
		}
		int kx,ky; cin>>kx>>ky;
		while(kx--){
			int p,v; cin>>p>>v; a[p]=v;
		}
		while(ky--){
			int p,v; cin>>p>>v; b[p]=v;
		}
	if(a[1]>b[1]){
		swap(an,am);
		for(int i=1;i<=max(n,m);i++){
			swap(a[i],b[i]);
			
		}
	}
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<"  ";
//		} cout<<endl;
//		for(int i=1;i<=m;i++){
//			cout<<b[i]<<"  ";
//		} cout<<endl;
		pd();// cout<<endl;
	} 
	return 0;
}
