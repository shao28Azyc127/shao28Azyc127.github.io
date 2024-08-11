#include<bits/stdc++.h>
using namespace std;

long long n,flag,cnt,d,mn=1e9,a[100100],y,b[100100];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i=1;i<=n-1;i++){
		cin >> a[i];
	}
	cin >> b[1];
	for(int i=2;i<=n;i++){
		cin >> b[i];
	}
	for(int i=1;i<=n-1;i++){
		mn=min(mn,b[i]);
		long long x=ceil((double)(a[i]-y)/(double)d);
		if(x<0){
			y=-1*x;
		}
		else y+=x*d-a[i];
		cnt+=x*mn;
		//cout<< x << endl;
	}
	cout << cnt;
	
	
	return 0;
}
