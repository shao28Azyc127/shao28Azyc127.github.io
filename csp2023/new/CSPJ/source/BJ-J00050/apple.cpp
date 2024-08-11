#include <bits/stdc++.h>
using namespace std;
freopen("apple.in",'r',stdin);
freopen("apple.out",'w',stdin);
int n,i=0,p=0,cnt=1,t=0,ans;
int a[100000000];
int main(){
	cin>>n;
	while (n-t){
		i++;
		if (i>n){
			i=1;
			p=0;
			cnt++;
		}
		if (a[i]==0){
			if (p%3==0){
				if (i==n) ans=cnt;
				a[i]=1;
				t++;
			}
			p++;
		}
	}
	cout<<cnt<<' '<<ans;
	return 0;
}