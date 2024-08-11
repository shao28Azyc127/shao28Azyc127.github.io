#include<bits/stdc++.h>
using namespace std;
int n,a[10],b[10],cnt;
bool vis[10][100005];
void jia(int x,int id){
	a[id]+=x;
	if(a[id]>9)a[id]=a[id]%10;
}
void jian(int x,int id){
	a[id]=a[id]-x;
	if(a[id]<0)a[id]=(20+a[id])%10;
}
int geth(){
	int ans=0,num=1;
	for(int i=5;i>=0;i--)ans+=a[i]*num,num*=10;
	return ans;
}
bool ok(int id){
	int ans=1;
	for(int i=1;i<=n;i++)ans&=vis[i][id];
	return ans;
}
void solve(int id){
	for(int i=1;i<=5;i++)cin>>a[i];
	for(int i=1;i<=5;i++){
		for(int j=1;j<=9;j++){
			jia(j,i);
			vis[id][geth()]=1;
			jian(2*j,i);
			vis[id][geth()]=1;
			jia(j,i);
		}
		
		if(i>1){
			for(int j=1;j<=9;j++){
				jia(j,i);
				jia(j,i-1);
				vis[id][geth()]=1;
				jian(2*j,i);
				jian(2*j,i-1);
				vis[id][geth()]=1;
				jia(j,i);
				jia(j,i-1);
			}
		}
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	if(n==1)cout<<81;//30pts
	else{
		for(int i=1;i<=n;i++)solve(i);
		int ans=0;
		for(int i=0;i<=99999;i++)if(ok(i))ans++;
		cout<<ans;
	}
}
//kkkbaoyou,monibiegua
