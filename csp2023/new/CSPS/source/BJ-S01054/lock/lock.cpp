#include<bits/stdc++.h>
using namespace std;
int a[15][10];
int mm[10];
int t,cnt;
int cha[10];
bool ky(int x){
	int jg=0,o1=0,o2=0,c;
	jg=0;
	for(int i=1;i<=5;i++)cha[i]=0;
	for(int j=1;j<=5;j++){
		if(a[x][j]!=mm[j]){
			if(mm[j]>a[x][j])c=mm[j]-a[x][j];
			else c=mm[j]+10-a[x][j];
			cha[j]=c;
			jg++;
			if(jg>2)return false;
			if(o1==0)o1=j;
			else o2=j;
		}
	}
	if(jg==1)return true;
	if(abs(o1-o2)!=1)return false;
	if(cha[o1]!=cha[o2])return false;
	return true;
}
void dfs(int wei){
	if(cnt==81)return;
	if(wei==5){
		for(int i=1;i<=t;i++){
			if(!ky(i))return;
		}
		cnt++;
		return;
	}
	for(int i=0;i<=9;i++){
		mm[wei+1]=i;
		dfs(wei+1);
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>t;
	if(t==1){
		cout<<81<<endl;
		return 0;
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
		}
	}
	dfs(0);
	cout<<cnt<<endl;
	return 0;
}