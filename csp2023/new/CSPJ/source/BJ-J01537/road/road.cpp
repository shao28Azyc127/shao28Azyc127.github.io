#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)

int n,d;
int u[100005],a[100005];
int houzhui[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>u[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				houzhui[i]++;
			}else{
				break;
			}
		}
	}
	//for(int i=1;i<n;i++){
	//	cout << houzhui[i]<<" ";
//	}
	int c=0,j=0;
	for(int i=1;i<n;i++){
		for(int jj=0;jj<=houzhui[i];jj++){
			c+=u[jj+i];
		}
		if(c%d==0){
			cout <<c<<" "<< c/d<<endl;
			j+=(c/d)*a[i];
			c=0;
		}else{
			cout <<c<<" "<< (c+d)/d<<endl;
			j+=(c+d)/d*a[i];
			c-=(c+d)/d*d;
		}
		i+=houzhui[i];
	}
	cout << j  << endl;
	return 0;
}
