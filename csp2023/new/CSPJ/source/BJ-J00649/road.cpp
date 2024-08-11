#include <iostream>
using namespace std;
int n,k;
int cnt;
int a[100010];
int b[100010];
int sum;
int ell;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>k;
	b[0]=10000010;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]>b[i-1]){
			b[i]=b[i-1];
		}
		// cout<<b[i];
	}
	b[n]=-1;
	for(int i=1;i<n;i++){
		cnt+=a[i];
		if(b[i]!=b[i+1]){
			cnt-=ell;
			int p=0;
			if(cnt%k==0) p=cnt/k;
			else p=cnt/k+1;
			sum+=p*b[i];
			ell=p*k-cnt;
			cnt=0;
		}
	}
	cout<<sum;
	return 0;
}