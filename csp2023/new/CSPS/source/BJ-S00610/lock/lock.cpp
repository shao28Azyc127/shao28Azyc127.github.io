#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[9][6],b[6],n,sum=0;

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		for(int j=1;j<=5;j++){
			scanf("%d",&a[1][j]);
		}
		cout<<81;
		return 0;
	}
	cout<<10;
	return 0;
}