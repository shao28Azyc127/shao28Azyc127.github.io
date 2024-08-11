#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	int a;
}k[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,ans=0;
	float m;
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>k[n].v;
	}
	for(int i=1;i<=n;i++){
		cin>>k[n].a;
	}
	for(int i=2;i<=n;i++){
		if(k[1].a<=k[i].a){
			ans+=k[i].v;
			m=ans/d/k[1].a;
		}
		else{
			m+=k[i].v/k[i].a*d;
		}
	}
	cout<<(int)m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}