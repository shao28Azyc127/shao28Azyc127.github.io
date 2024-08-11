#include<bits/stdc++.h>
using namespace std;
int n,ans[100005],a[6],cnt=0;
int work(){return a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=5;i++)cin>>a[i];
		for(int i=1;i<=5;i++){
			for(int j=1;j<=9;j++){
				a[i]=(a[i]+1)%10;
				ans[work()]++;
			}
			a[i]=(a[i]+1)%10;
		}
		for(int i=1;i<=4;i++){
			for(int j=1;j<=9;j++){
				a[i]=(a[i]+1)%10;
				a[i+1]=(a[i+1]+1)%10;
				ans[work()]++;
			}
			a[i]=(a[i]+1)%10;
			a[i+1]=(a[i+1]+1)%10;
		}
	}
	for(int i=0;i<=99999;i++)if(ans[i]==n)cnt++;
	cout<<cnt;
	return 0;
}
