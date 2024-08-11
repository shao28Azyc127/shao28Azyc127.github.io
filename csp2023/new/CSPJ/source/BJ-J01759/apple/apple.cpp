#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("apple.in","r",stdin);
	//freopen("apple.out","w",stdout);
	int n,m,cnt=0;
	cin>>n;
	m=n;
	while(m!=0){
		int x;
		x=int(m/3.0+0.5);
		if(x==0){
			m-=1;
		}
		m-=x;
		cnt++;
	}
	cout<<cnt<<" ";
	cout<<cnt;
	return 0;
}
