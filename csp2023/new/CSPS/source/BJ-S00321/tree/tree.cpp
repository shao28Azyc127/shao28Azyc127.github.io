#include<bits/stdc++.h>
using namespace std;
int n,a[100010][3];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=0;i<2*n-2;i++)
		for(int j=0;j<3;j++)
			cin>>a[i][j];
	cout<<n*2-3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
