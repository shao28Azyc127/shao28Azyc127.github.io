#include<bits/stdc++.h>
using namespace std;
int n,d,now;
//queue<int> q;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	//for(int i=1;i<=n;i++) q.push(i);
	for(d=1;n;d++){
		if(n%3==1&&!now) now=d;
		n-=n%3==0?n/3:n/3+1;
	}
	cout << d-1 << ' ' << now;
	return 0;
}
