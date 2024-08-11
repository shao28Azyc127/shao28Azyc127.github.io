#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> h[N];
struct node{
	int a,b,c;
}a[N];
int t[N];
int u,v;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	for(int i=1;i<n;i++){
		cin>>u>>v;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			t[j]=t[j]+max(a[j].b+i*a[j].c,1);
	
	int day=n+1;
	while(true){
		for(int i=1;i<=n;i++) t[i]=t[i]+max(a[i].b+day*a[i].c,1);
		bool flag=1;
		for(int i=1;i<=n;i++) flag=flag&&(t[i]>=a[i].a);
		if(flag) break;
		day++;
	}
	cout<<day;
	return 0;
}