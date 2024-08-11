#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
	int t;
};
node x[20005];
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.in","w",stdout);
	int n,m,k;
	int maxt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b>>x[i].t;
		if(maxt<x[i].t){
			maxt=x[i].t;
		}
	}
	cout<<maxt+k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
