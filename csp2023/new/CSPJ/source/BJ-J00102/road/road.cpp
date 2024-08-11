#include<bits/stdc++.h>
using namespace std;
int n,d,v[100010],a[100010],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	int dis=1;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int last=0;
	while(dis<n){
		int b=1,f=v[dis],num;
		while(a[dis]<=a[dis+b]&&(dis+b)<n){		
			f+=v[dis+b];
			b++;
		}
		f-=last;
		if(f%d==0){
			num=f/d*a[dis];
		}
		else{
			num=(f/d+1)*a[dis];
			last=(f/d+1)*d-f;
		}
		ans+=num;
		dis+=b;
	}
	cout<<ans;
	return 0;
}