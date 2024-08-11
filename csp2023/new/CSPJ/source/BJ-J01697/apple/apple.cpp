#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	int cnt=n;
	int ans1=0,ans2=0;
	while(cnt>0){
		ans1++;
		sort(a+1,a+n+1,cmp);
		int sum=0;
		for(int i=1;i<=cnt;i+=3){
			if(a[i]==n){
				ans2=ans1;
			}
			a[i]=0x3f3f3f3f;
			sum++;
		}
		cnt-=sum;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
