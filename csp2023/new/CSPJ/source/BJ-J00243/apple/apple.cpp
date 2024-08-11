#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int a[1000005]={};
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,i,s,c,w;
	cin>>n;
	c=n;
	w=1;
	while(c>0){
		s=0;
		for(i=1;i<=n;i++){
			s=s%3;
			if(a[i]==0){
				if(s==0){
					a[i]=w;
					c--;
				}
				s++;
			}
		}
		w++;
	}
	cout<<w-1<<" "<<a[n];
	return 0;
}

