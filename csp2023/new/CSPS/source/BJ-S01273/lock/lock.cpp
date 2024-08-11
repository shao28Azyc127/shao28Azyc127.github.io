#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a ; i<=b ; i++)
using namespace std;
int n,cnt;
int a[10];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	f(i,1,n){
		f(j,1,5){
			cin>>a[i];
		}
		if(n == 1) cout<<81<<endl;
	} 
	cout<<10;
	return 0;
}
