#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int a1[600008];
int b1[600008];
int a[600008];
int b[600008];

int c,n,m,q,flag;
int chk1(int x,int y){
	//cout<<"1:  "<<x<<' '<<y<<endl;
	int ans=0;
	if(x==n&&y==m){
		flag=1;
		return 1;
	}
	if(flag==1) return 1;
	if(y<m&&a[x]>b[y+1])ans=max(ans,chk1(x,y+1));
	if(x<n&&a[x+1]>b[y])ans=max(ans,chk1(x+1,y));
	return ans;
}
int chk2(int x,int y){
	//cout<<"2:  "<<x<<' '<<y<<endl;
	int ans=0;
	if(x==n&&y==m){
		flag=1;
		return 1;
	}
	if(flag==1) return 1;
	if(y<m&&a[x]<b[y+1])ans=max(ans,chk2(x,y+1));
	if(x<n&&a[x+1]<b[y])ans=max(ans,chk2(x+1,y));
	return ans;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
		a[i]=a1[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b1[i];
		b[i]=b1[i];
	}
	if((a[1]<=b[1]&&a[n]>=b[m])||(a[1]>=b[1]&&a[n]<=b[m]))cout<<0;
	else{
		//cout<<"ok";
		flag=0;int x=chk1(1,1);//cout<<endl;
		flag=0;int y=chk2(1,1);
		cout<<max(x,y);
	}
	while(q--){
		int k1,k2;
		for(int i=1;i<=n;i++){
			a[i]=a1[i];
		}
		for(int i=1;i<=m;i++){
			b[i]=b1[i];
		}
		cin>>k1>>k2;
		for(int i=1;i<=k1;i++){
			int u,v;
			cin>>u>>v;
			a[u]=v;
		}
		for(int i=1;i<=k2;i++){
			int u,v;
			cin>>u>>v;
			b[u]=v;
		}
		if((a[1]<=b[1]&&a[n]>=b[m])||(a[1]>=b[1]&&a[n]<=b[m]))cout<<0;
		else{
			//cout<<"ok";
			flag=0;int x=chk1(1,1);//cout<<endl;
			flag=0;int y=chk2(1,1);
			cout<<max(x,y);
		}
	}
	return 0;
}
