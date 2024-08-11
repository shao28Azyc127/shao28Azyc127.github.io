#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long a[10005];
	for(long long i=1;i<=n;i++){
		a[i]=i;
	}
	long long j=1,i=1,cnt=0,num;
	a[i]=0;
	while(true){
		if(a[n]==0){
			num=cnt;
		}
		i++,j++;
		if(j==2){
			a[i]=0;
		}
		cnt++;
	}
	cout<<cnt<<" "<<num;
	return 0;
}
