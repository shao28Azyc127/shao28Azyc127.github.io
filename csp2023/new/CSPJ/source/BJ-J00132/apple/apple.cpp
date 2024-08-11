#include<bits/stdc++.h>
using namespace std;
int shibie(int a[]){
	for(int i=0;i<400000;i++)
	{
		if(a[i]!=0)
			return 1;
	}
	return 0;
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,m=1,cnt=0,k=0,ct;
	//const int q;
	int nw;
	cin>>n;
	int a[400000]={ };
	for(int i=0;i<n;i++)
	{
		if(i%3!=1){
			a[m]=i;
			m++;
		}
		cnt++;ct++;
		if(n%3==1)
			nw=1;
	}
	while(shibie(a)==1)
	{
		for(int i=0;i<400000;i++)
		{
			if(a[i]>0)
			{
				k++;
				if(k%3==1)
					a[i]=0;
			}
		}
		cnt++;
		if(a[n]==0){
			nw=cnt;
			const int q=nw;
			//cout<<q;
		}
	}
	
	cout<<cnt-8<<" "<<nw-8;
}
