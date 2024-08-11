#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	int m=0,sheng=0;
	int a[100005],v[100005];
	cin>>n>>d;
	int sum=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	m+=ceil(a[2]*1.0/d)*v[1];
	sheng+=m/v[1]*d;
	for(int i=2;i<n;i++){
		if(v[i+1]>v[i]){
			sum+=a[i+1]+a[i+2]-sheng;
			m+=ceil(sum*1.0/d)*v[i];
			sheng=m/v[i]*d;
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
