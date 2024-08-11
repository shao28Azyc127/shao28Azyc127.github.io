#include<bits/stdc++.h>
using namespace std;
double s=0,n,d,x,b[100010],a[100010];
int ss,cnt;
int minn;
double fun(double x){
	double sx=0;
	minn=INT_MAX;
	for(int i=n-1;i>=1;i--){
		if(a[i]<=n){
			minn=a[i];
			cnt=i;
		}
	}
	for(int i=cnt;i<n;i++){
		ss+=b[i];
	}
	sx+=1.0*ss/d;
	ss=0;
	if(cnt!=1){
		s+=fun(cnt);
	}else{
		return sx;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>x;
		b[i]=x;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=x;
	}
	cout<<fun(n);
	return 0;
}
//no!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!