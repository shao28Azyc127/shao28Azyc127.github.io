#include<bits/stdc++.h>
using namespace std;
int n,a[1001000],d;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	int s=0;
	for(int i=1;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	int m;
	cin>>m;
	cout<<(s/d+(s%d!=0))*m;
	return 0;
}
