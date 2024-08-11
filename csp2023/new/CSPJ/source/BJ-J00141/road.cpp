#include<bits/stdc++.h>
using namespace std;
int a[100009],n,e,b[100009],d[100009],v=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>e;
	for(int i=1;i<=n-1;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int x=b[1],y=1,z=0;
	for(int i=1;i<=n;i++){
		if(b[i]<x){
			d[y]=z;
			z=0;
			x=b[i],y=i;
		}
		if(i==n-1){
			int ans=0;
			for(int j=y;j<n;j++){
				ans+=a[j];
			}
			d[y]=ans;
		}
		z+=a[i];
	}
	int u=0;
	for(int i=n;i>=1;i--){
		u+=a[i];
		if(d[i]!=0){
			d[i]=u;
			break;
		}
	}
	long long sum=0;
	int l=0,h;
	for(int i=1;i<=n;i++){
		if(d[i]!=0){
			h=l;
			l=d[i]-l;
			l=ceil(l*1.0/e);
			sum=sum+l*b[i];
			l*=e;
			l-=d[i];
			l+=h;
		}
	}
	cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
