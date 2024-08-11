#include<iostream>
#include<cstdio>
using namespace std;
int n,cnt,hehe;
int main() {
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n) {
		cnt++;
		if(n%3==1&&!hehe)
			hehe=cnt;
		n-=(n+2)/3;
	}
	cout<<cnt<<" "<<hehe<<"\n";
	return 0;
}
