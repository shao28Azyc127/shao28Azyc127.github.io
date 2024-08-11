#include<bits/stdc++.h>
using namespace std;
int n,a[6];
set<int> s,cntN;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int T=1;T<=n;T++){
		for(int i=1;i<=5;i++)cin>>a[i];
		if(n==1){
			cout<<81<<endl;
			return 0;
		}
		cntN.insert(a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5]);
		int X[6];
		for(int i=1;i<=5;i++)X[i]=a[i];
		for(int i=1;i<=5;i++){
			for(int j=0;j<=9;j++){
				if(j==a[i])continue;
				a[i]=(a[i]+j)%10;
				s.insert(a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5]);
				a[i]=X[i];
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=0;j<=9;j++){
				if(j==a[i])continue;
				a[i]=(a[i]+j)%10;
				a[i+1]=(a[i+1]+j)%10;
				s.insert(a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5]);
				a[i]=X[i];
				a[i+1]=X[i+1];
			}
		}		
	}
	int N=cntN.size()*81;
	if(cntN.size()==1){
		cout<<81<<endl;
		return 0;
	}
	cout<<N-s.size()<<endl;
	return 0;
}
