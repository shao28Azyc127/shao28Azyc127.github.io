#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int n,a[15][15],m[5],s=1,l,d,k=1;
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
		}
	}
	for(int j=1;j<=5;j++){
		int x=a[1][j];
		l=0;
		for(int i=1;i<=n;i++){
			
			if(a[i][j]!=x){
				l=1;
				m[k]=abs(a[i][j]-x);
				k++;
				
			}
		}
		if(l==1){
			if(s==0){
			cout<<0;
			return 0;
			}else{
			d++;
			s=2;
			}
			
		}else{
			if(s==2){
				s=0;
			}
		}
	}
	if(n==2){
	if(d==1){
		cout<<10;
	}else if(d==2){
		if(m[1]+m[2]==10||m[1]==m[2])
		cout<<10;
		else
		cout<<5;
	}
}else if(n==1){
	cout<<81;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
