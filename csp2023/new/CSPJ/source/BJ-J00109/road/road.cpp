#include<bits/stdc++.h>
using namespace std;
int n,d,ans,sy,a[100005],b[100005];
bool jy[100006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i=1;i<n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	ans=b[1]*((a[1]+d-1)/d);
	sy=((a[1]+d-1)/d)*d;
	jy[1]=1;
	int k=2;
	int ls=0;
	while(b[1]<b[k]){
		if(k==n||jy[k]){
			break;
		}
		ans+=b[1]*((a[k]+d-1-sy+ls)/d);
		sy+=((a[k]+d-1-sy+ls)/d)*d;
		ls+=a[k];
		jy[k]=1;
		k++;
	}
	for(int i=2;i<n;i++){
		sy-=a[i-1];
		int k=i;
		int ls=0;
		while(b[i]<=b[k]){
			if(k==n||jy[k]){
				break;
			}
			ans+=b[i]*((a[k]+d-1-sy+ls)/d);
			sy+=((a[k]+d-1-sy+ls)/d)*d;
			ls+=a[k];
			jy[k]=1;
			k++;
		}
		//if(b[i]<b[i+1]&&sy<a[i+1]){
			//sy=sy+((a[i]+d-1-sy)/d)*d;
			//ans+=b[i]*((a[i]+d-1-sy)/d);
		//}
	}
	cout << ans;
	return 0;
}
