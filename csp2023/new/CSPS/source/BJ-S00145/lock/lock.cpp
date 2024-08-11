#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
int n,ans;
int a[20][10],c[10];
int check(){
	for(int i=1;i<=n;i++){
		int t=0,k=0,tt=0;
		for(int j=0;j<5;j++){
			if(a[i][j]!=c[j]){
				int kk=a[i][j]-c[j];
				if(!t) t++,tt=j,k=a[i][j]-c[j];
				else if(t==1&&tt==j-1&&(k==kk||k+10==kk||k==kk+10)) t++;
				else return 0;
			}
		}
		if(t==0) return 0;
	}
	return 1;
}
void dfs(int x){
	if(x==5){
		if(check()) ans++;
		return;
	}
	for(int i=0;i<=9;i++) c[x]=i,dfs(x+1);
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
	dfs(0);
	cout<<ans;
	return 0;
}
