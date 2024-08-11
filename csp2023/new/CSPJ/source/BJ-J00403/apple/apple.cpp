#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int nf=n,cnt=0,xxb=0;
	bool sf=1;
	while(nf){
		cnt++;
		if(nf%3==1&&sf){
			xxb=cnt;
			sf=0;
		}
		nf-=(nf+2)/3;
	}
	cout<<cnt<<" "<<xxb;
	cnt=0;
	return 0;
}
