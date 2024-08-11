#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int a[5];
int n,k[10][5];
bool check(){
	for(int i=0;i<n;i++){
		int d[5];
		for(int j=0;j<5;j++)d[j]=(a[j]-k[i][j]+10)%10;
		int chgs=0;
		int chg[10];
		for(int j=0;j<5;j++){
			if(a[j]!=k[i][j])chg[chgs++]=j;
		}
		if(chgs>2||chgs==0)return false;
		if(chgs==2&&d[chg[0]]!=d[chg[1]])return false;
		if(chgs==2&&chg[1]!=chg[0]+1)return false;
	}
	return true;
}
void dfs(int x){
	if(x==5){
		if(check())cnt++;
		return;
	}
	for(int i=0;i<10;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++)cin>>k[i][j];
	}
	dfs(0);
	cout<<cnt;
}