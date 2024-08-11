#include<bits/stdc++.h>
using namespace std;
int n,sum,cnt;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int tmp=n;
	while(tmp){
		int i=(tmp+2)/3;
		tmp-=i;
		cnt++;
	}
	cout<<cnt;
	bool flag=0;
	tmp=n;
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<=tmp;j+=3){
			cnt++;
			if(j==tmp)	flag=1;
		}
		tmp-=cnt;
		if(flag){
			cout<<" "<<i;
			break;
		}	
	}
}
