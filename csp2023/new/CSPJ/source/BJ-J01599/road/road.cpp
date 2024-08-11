#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int v[maxn];
int a[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
int n,d,x,y=0,mi=maxn,jl1=0;
cin>>n>>d;
v[0]=0;
for(int i=1;i<n;i++){
	cin>>x;
	v[i]=v[i-1]+x;
}
for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]<mi&&i!=n-1){mi=a[i];jl1=i;}
}
if(y==jl1){
int jl=v[n-1];
if(jl%d==0){
	y=jl/d*a[0];
}
else{
	y=(jl/d+1)*a[0];
}
cout<<y;}
else{
int f=0;
for(int i=0;i<n;i++){
	for(int k=i+1;k<n;k++){
		if(a[k]<a[i]){
			int jl=v[k]-v[i];
			if(jl%d==0){
				y+=jl/d*a[i];
			}
			else{
				y+=(jl/d+1)*a[i];
			}
			i=k;
			if(i==n-1){
				f=1;
			}
			cout<<y<<endl;
			break;
		}
	}
	if(f){break;}
	}
	cout<<y;}
	return 0;
}