#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int picktime=0,anstime=0,checkn=n;
	while(checkn!=0){
		checkn-=(checkn-1)/3+1;
		anstime++;
	}
	if(n%3==1) picktime=1;
	else if(n%3==2) picktime=anstime;
	else{
		if(anstime%2==1){
			picktime=(anstime-1)/2+1;
		}
		else{
			picktime=anstime/2;
		}
	}
	cout<<anstime<<" "<<picktime;
	return 0;
}
