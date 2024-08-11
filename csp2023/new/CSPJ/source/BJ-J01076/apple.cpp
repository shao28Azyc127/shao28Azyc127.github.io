#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+11;
long long a[N];
int main (){
	long long i,j;
	long long n,m,f0,f1=0,l=0,k,to=1,we=0;
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	f0=n;
	for(i=1;i<=n;i++){
		a[i]=i;
		we++;
	}
	while(to<=we){
		f1++;
		j=0;
		long long d=to,e=we;
		for(i=d;i<=e;i++){
			if(j>2){
				j=0;
			}
			if(j==0){
				to++;
				if(a[to-1]==n){
					k=f1;
				}
			}
			else{
				a[++we]=a[i];
				to++;
				j++;
			}
			if(j==0){
				j++;
			}
		}
	}
	cout<<f1<<" "<<k;
	return 0;
}