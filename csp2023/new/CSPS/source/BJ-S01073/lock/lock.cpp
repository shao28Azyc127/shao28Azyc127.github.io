#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int ans=0;
bool check(int i,int j,int k,int l,int m,int p){
	int cnt=0,x,y,rt;
	if(i!=a[p][1]) {cnt++; x=i; y=a[p][1];}
	if(j!=a[p][2]) {cnt++; x=j; y=a[p][2];}
	if(k!=a[p][3]) {cnt++; x=k; y=a[p][3];}
	if(l!=a[p][4]) {cnt++; x=l; y=a[p][4];}
	if(m!=a[p][5]) {cnt++; x=m; y=a[p][5];}
	if(cnt>=3 || cnt==0) return 0;
	else{
		rt=(x-y+10)%10;
	}
	if(i==(a[p][1]+rt+10)%10 && cnt==1) return 1;
	if(j==(a[p][2]+rt+10)%10 && cnt==1) return 1;
	if(k==(a[p][3]+rt+10)%10 && cnt==1) return 1;
	if(l==(a[p][4]+rt+10)%10 && cnt==1) return 1;
	if(m==(a[p][5]+rt+10)%10 && cnt==1) return 1;
	if(i==(a[p][1]+rt+10)%10 && j==(a[p][2]+rt+10)%10 && cnt==2) return 1;
	if(j==(a[p][2]+rt+10)%10 && k==(a[p][3]+rt+10)%10 && cnt==2) return 1;
	if(k==(a[p][3]+rt+10)%10 && l==(a[p][4]+rt+10)%10 && cnt==2) return 1;
	if(l==(a[p][4]+rt+10)%10 && m==(a[p][5]+rt+10)%10 && cnt==2) return 1;
	return 0;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
	}
	for(int i=0;i<=9;i++)
	for(int j=0;j<=9;j++)
	for(int k=0;k<=9;k++)
	for(int l=0;l<=9;l++)
	for(int m=0;m<=9;m++){
		bool f=0;
		for(int p=1;p<=n;p++){
			if(f==1) continue;
			if(!check(i,j,k,l,m,p)){
				f=1;
				continue;
			}
		}
		if(f==0) ans++;
	}
	cout<<ans;
	return 0;
}