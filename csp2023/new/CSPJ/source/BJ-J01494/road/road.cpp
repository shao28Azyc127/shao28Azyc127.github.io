#include<iostream>
using namespace std;
unsigned long long v[1000005],a[1000005],minn=1145140,tjd[1000005],tjdnum[1000005];
unsigned long long n,j=1,k=1,d,v1,minn2,jzd=1;
unsigned long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(unsigned long long i=1;i<=n-1;i++){
		cin>>v[i];
		v1=v1+v[i];
	}
	for(unsigned long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn){
			minn=a[i];
			minn2=i;
		}
	}if(a[1]==minn){
		if(v1%d==0)ans=v1/d*minn;
		else ans=(v1/d+1)*minn;
		cout<<ans<<endl;
		return 0;
	}else{
		for(unsigned long long i=1;i<=n;i++){
			if(a[i]<a[1]&&i<=minn2){
				tjd[k]=a[i];
				tjdnum[k]=i;
				k++;
			}
		}
		ans=0;
		k=1;
		v1=0;
		for(unsigned long long i=1;i<=k;i++){
			v1=v1+v[i];
			if(i==tjdnum[k]){
				if(v1%d==0)ans=ans+a[jzd]*v1/d;
				else ans=ans+a[jzd]*(v1/d+1);
			}
			jzd=i;
			v1=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
