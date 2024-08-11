#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int day=0,ans2=0,cnt=n;
	bool p=0;
	while(1){
		if(cnt<=3){
			day+=cnt;
			break;
		}
		day++;
		if(cnt%3==1&&!p){
			ans2=day;
			p=1;
		}
		cnt-=cnt/3+(cnt%3!=0);
	}
	if(ans2==0) ans2=day;
	cout<<day<<" "<<ans2;
	return 0;
}
