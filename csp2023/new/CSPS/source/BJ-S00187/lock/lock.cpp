#include<bits/stdc++.h>
using namespace std;
int n;
int a[10];
int b[10];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<81;
	}
	if(n==2){
		for(int i=1;i<=5;i++) cin>>a[i];
		for(int i=1;i<=5;i++) cin>>b[i];
		int sum=0;
		int x[10];
		for(int i=1;i<=5;i++){
			if(a[i]!=b[i])
			sum++;
			x[sum]=i;
		}
		if(sum==1) cout<<10;
		if(sum==2&&x[1]==x[2]-1&&a[x[1]]-b[x[1]]==a[x[2]]-b[x[2]]) 
		cout<<12;
		if(sum==2&&x[1]!=x[2]-1) cout<<2;
	}
    return 0;
}
