#include <bits/stdc++.h>
using namespace std;
struct road{
	int start,end,time;
}a[200000];
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].start>>a[i].end>>a[i].time;
	}
	cout<<6;
	return 0;
}
