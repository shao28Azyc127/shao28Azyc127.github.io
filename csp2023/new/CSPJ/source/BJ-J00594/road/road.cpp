#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005],lg[100005];
int n=0,d=0,minn=0,ans=0,zv=0,l=0,r=0,q=1,kkk;
int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
	cin>>n;
	cin>>d;
	for(int i=1;i<=n-1;i++){
		cin>>v[i];
		zv+=v[i];
	}
	for(int i=1;i<=n-1;i++){
		cin>>a[i];
		if(i==1)minn=1;
		else{
			if(a[minn]>a[i])minn=i;
		}
	}
	cin>>a[n];
	if(minn==1){
        if(zv%d==0)cout<<(zv/d)*a[1];
        else cout<<(zv/d+1)*a[1];
        return 0;
	}
	lg[0]=n;
	l=1,r=n;
	//lg[q]=minn;
	//q++;
	while(l!=r){
        minn=l;
		for(int i=1;i<=r-1;i++){
			if(a[minn]>=a[i])minn=i;
		}
		r=minn;
		lg[q]=r;
		q++;
	}
	kkk=q;
	for(int i=1;i<=kkk+1;i++){
		int z;
		for(int i=lg[q];i<=lg[q-1]-1;i++){
			z+=v[i];
		}
		if(z%d==0){
			ans+=(z/d)*a[lg[q]];
		}
		else {
			ans+=(z/d+1)*a[lg[q]];
		}
		if(q-1>=0)q--;
		else break;
	}
	cout<<ans;
	return 0;
}
