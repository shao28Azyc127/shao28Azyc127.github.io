#include <bits/stdc++.h>
using namespace std;
int a[1000000010];
int b[1000000010];
int p=1;
bool t(int k){
	for(int i=1;i<=k;i++){
		if(b[i]>0) return true;
	}
	return false;
}
int main(){
	freopen("apple","r",stdin);
	freopen("apple","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		b[i]=i;
		a[i]=i+1;
	}
	a[n]=1;
	int len=n;
	int ans=0;
	int x;
	while(t(n)){
		ans++;
		for(int i=1;i<=(len-1)/3+1;i++){
			a[p]=a[a[p]];
			for(int j=1;j<=3;j++){
				p=a[p];
			}
			if(p-1==n) x=ans;
			b[p-1]=0;
			a[p]=a[a[p]];
		}
	}
	cout<<ans<<" "<<x;
	return 0;
}
