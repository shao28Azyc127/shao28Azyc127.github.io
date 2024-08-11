#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],c[100010],u,v,d,cnt,vis[100010];
bool f(){
	int t=0;
	for(int i=1;i<=n;i++)if(a[i]>vis[i])return 0;
	return 1;
}
bool f1(){
	int t=0;
	for(int i=1;i<=n;i++)if(1>vis[i])return 0;
	return 1;
}
void f2(){
	for(int i=1;i<=cnt;i++)vis[i]+=max(1,b[i]+c[i]*d);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<n;i++)cin>>u>>v;
	while(!f()){
		d++;
		if(!f1())cnt++;
		f2();
	}
	cout<<d;
	return 0;
}