#include <bits/stdc++.h>
using namespace std;
//method1:changeintoint
int n;
int a[10][6],arr[10];

int s(int v,int t){
	int res=v;
	for(int i=2;i<=t;i++){
		res*=v;
	}
	return res;
}

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=9;i++){
		arr[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
			arr[i]+=a[i][j]*s(10,j-1);
		}
	}
	int x=99999,ans=0; 
	while(x>=0){

		for(int i=1;i<=n;i++){
			if(arr[i]==x-1 || arr[i]==x+1 || arr[i]==x+10 || arr[i]==x-10 || arr[i]==x+100 || arr[i]==x-100 || arr[i]==x+1000 || arr[i]== x-1000 || arr[i]==x+10000 || arr[i]==x-10000 || arr[i]==x+11 || arr[i]==x-11 || arr[i]==x+110 || arr[i]==x-110 || arr[i]==x+1100 || arr[i]==x-1100 || arr[i]==x+11000 || arr[i]==x-11000){
				ans++;
				
			}
		}
		x--;
	}
	cout<<ans;
	return 0;
}
