#include <bits/stdc++.h>
using namespace std;
freopen("road.in",'r',stdin);
freopen("road.out",'w',stdout);
int n,d,t,cnt=0,flag;
int u[100005];
int a[100005];
int main(){
	cin>>n>>d;
	for (int i=2;i<=n;i++){
		cin>>t;
		u[i]=t+u[i-1];
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	t=0;
	for (int i=1;i<=n;i=i){
		flag=1;
		for (int j=i+1;j<=n;j++){
			if (flag && a[j]<a[i]){
				cnt+=((u[j]-u[i]+d-(u[j]-u[i])%d)/d-t)*a[i];
				cout<<i<<' '<<(u[j]-u[i]+d-(u[j]-u[i])%d)/d-t<<' '<<t<<endl;
				t=(d-(u[j]-u[i])%d)/d-t;
				i=j;
				flag=0;
			}
		}
		if (flag){
			cnt+=((u[n]-u[i]+d-(u[n]-u[i])%d)/d-t)*a[i];
			break;
		}
	}
	cout<<cnt;
	return 0;
}
