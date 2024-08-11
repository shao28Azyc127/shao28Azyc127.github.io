#include <bits/stdc++.h>
using namespace std;
int n,now,day,w,f;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	now=n;
	day=1;
	while(now!=0){
		if(now%3==1&&f==0){
			w=day;
			f=1;
		}
		now-=(now+2)/3;
		day++;
	}
	day--;
	cout << day << ' ' << w;
	return 0;
}
