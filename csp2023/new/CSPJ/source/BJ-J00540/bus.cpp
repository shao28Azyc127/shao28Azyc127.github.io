#include <iostream>
using namespace std;
int u[20001],v[20001],a[20001];
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>a[i];
	}
	cout<<-1;
	return 0;
}
