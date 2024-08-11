#include<bits/stdc++.h>
using namespace std;
int s[6];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int a,cnt=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cnt=0;
		for(int j=1;j<=5;j++){
			cin>>s[j];
		}
		for(int j=1;j<=5;j++){
			cnt+=10-s[j];
			cnt+=s[j]-1;
		}
		for(int j=2;j<=5;j++){
			cnt+=9;
		}
	}
	cout<<cnt;
	return 0;
}
