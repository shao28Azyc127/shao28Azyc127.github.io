#include<bits/stdc++.h>
using namespace std;
int w[100005],v[100005],e,n,q;
long long S,T,d;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	q=n;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	long long minn=w[1];
	for(int i=2;i<=n;i++){
		T+=v[i-1];
		if(w[i]<minn||i==n){
			long long tmp=T/d;
			if(T<=tmp*d+e){
				S+=(tmp*minn);
				e=(tmp*d+e)-T;
			}else{
				S+=(tmp*minn)+minn;
				e=(tmp*d+e+d)-T;
			}
			minn=w[i];
			T=0;
		}
	}
	cout<<S;
	return 0;
}
