#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,k,d=0,z,f,y=0,a[1000005]={0},sig=1;
	cin>>n;
	k=n;
	while(k!=0){
		if(k%3==0){
			z=k/3;
		}
		else{
			z=1+k/3;
		}
		k-=z;
		d++;
	}
	cout<<d<<" ";
	while(sig!=0){
		f=1;
		y++;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				f--;
				if(f==0){
					a[i]=1;
					f=3;
					if(i==n){
						cout<<y;
						sig=0;
					}
				}	
			}
		}
	}
	return 0;
}