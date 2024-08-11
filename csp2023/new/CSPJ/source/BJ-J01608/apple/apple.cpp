#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int cnt=0,v;
	bool xxx=0;
	int n;
	cin>>n;
	while(n>0){
		++cnt;
		if(n%3==1&&xxx==0){
			v=cnt;
			xxx=1;
		}
		n=n-((n-1)/3+1);
	}
	cout<<cnt<<' '<<v<<endl;
	return 0;
}
