#include <bits/stdc++.h>
using namespace std;
int a[100005];
int v[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,d;
    long long l=0;
    int mina=1e9;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
		cin>>v[i];
		l+=v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mina=min(mina,a[i]);
	}
    int y=(l+(d-1))/d;
    if(mina==a[1]){
		cout<<y*a[1];
		return 0;
	}
    int ans=0,lz=0;
    y=(v[1]+(d-1))/d;
    mina=1e9;
	ans+=a[1]*y;
	lz=y*d-v[1];
	mina=a[1];
    for(int i=3;i<=n;i++){
		y=(v[i-2]+(d-1))/d;
		lz+=y*d-v[i-2];
		if(lz>=d){
			y-=1;
			lz-=d;
		}
		if(a[i-1]>mina){
			ans+=mina*y;
		}
		else{
			mina=a[i-1];
			ans+=mina*y;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5
*/
