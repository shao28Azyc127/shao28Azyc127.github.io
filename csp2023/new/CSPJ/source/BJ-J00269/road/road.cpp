#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,qian=0,you;
	cin>>n>>d;
	int a[10000],b[10000];
	for(int i=1;i<=n-1;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d*j+you>=a[i]){
				you=d*j-b[i];
				qian=qian+j*b[i-1];
				break;
			}
		}
	}
	cout<<qian<<endl;
	return 0;
}