#include<iostream>
#include<cmath>
using namespace std;
bool b[1000005];

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,ls,cnt=0;
	cin>>n;
	ls=n;
	while(ls!=0){
		ls-=ceil(ls*1.0/3);
		cnt++;
	}
	cout<<cnt<<" ";
	int cnt1=0;
	while(cnt1<=cnt){
		int cur=1,cur1=0;
		cnt1++;
		while(b[cur]) cur++;
		b[cur]=true;
		while(cur<=n){
			if(!b[cur]) cur1++;
			if(cur1==3){
				b[cur]=true;
				cur1=0;
			}
			cur++;
		}
		if(b[n]){
			cout<<cnt1;
			return 0;
		}
	}
	if(b[n]) cout<<cnt1;
	return 0;
}	
