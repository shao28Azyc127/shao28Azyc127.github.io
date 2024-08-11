#include<bits/stdc++.h>
using namespace std;

int zhs(int a,int b){
	int a1=1,b1=1;
	for(int i=1;i<=b;i++){
		a1*=a;
		a--;
		//cout<<a1<<endl;
	}
	for(int i=1;i<=b;i++){
		b1*=b;
		b--;
	}
		return a1/b1;
}

struct mms{
	int mm[10]={1};
};
mms a[15];
int n,ans=1,x=10;

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
	        cin>>a[i].mm[j];
	    }
	}
	int x=5;
	for(int i=n;i>0;i--){
		ans=zhs(x*2,2)+zhs(x*2-1,2);
		//cout<<zhs(*2,2)<<endl;
		x--;
	}
	cout<<ans;
	return 0;
}
