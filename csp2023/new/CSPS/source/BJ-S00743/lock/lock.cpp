#include<bits/stdc++.h>
using namespace std;
int s[10][10][10][10][10],a[10][10],ans;
int n;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=5;j++)cin>>a[i][j];
		s[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]=1;
	}
	for(i=1;i<=n;i++)for(j=1;j<=5;j++)for(int k=0;k<=9;k++){
		int t[6]={0,a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]};
		t[j]+=k;
		if(t[j]>9)t[j]-=10;
		if(!s[t[1]][t[2]][t[3]][t[4]][t[5]])ans++;
		s[t[1]][t[2]][t[3]][t[4]][t[5]]=1;
	}
	for(i=1;i<=n;i++)for(j=1;j<=4;j++)for(int k=0;k<=9;k++){
		int t[6]={0,a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]};
		t[j]+=k;
		t[j+1]+=k;
		if(t[j]>9)t[j]-=10;
		if(t[j+1]>9)t[j+1]-=10;
		if(!s[t[1]][t[2]][t[3]][t[4]][t[5]])ans++;
		s[t[1]][t[2]][t[3]][t[4]][t[5]]=1;
	}
	cout<<ans;
	return 0;
}
