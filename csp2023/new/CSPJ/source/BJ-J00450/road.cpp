#include<bits/stdc++.h>
using namespace std;
struct node{
	int b,m;
}zhan[100010];
int ju[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int oil,n;

	cin>>n>>oil;
	for(int i=1;i<n;i++){
		cin>>ju[i];
	}
	for(int i=1;i<=n;i++){
		cin>>zhan[i].m;
		zhan[i].b=i;
	}
	int i=1;
	int j=1;
	long long ans=0;
	int yk=0;
	while(j!=n){
		for(i;zhan[i].m>=zhan[j].m&&i<=n;i++);
		long long km=0;
		for(int k=j;k<i;k++){
			km+=ju[k];
		}
		km-=yk;
		yk=0;
		int y=(km%oil==0)?km/oil:km/oil+1;
		yk=y*oil-km;
		ans+=y*zhan[j].m;
		j=i;
	}
	cout<<ans;
	return 0;
}