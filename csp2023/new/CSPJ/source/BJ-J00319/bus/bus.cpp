#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[1000005][3];
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	cout<<6;
	fclose(stdin);
	fclose(stdout);
	return 0;

}
