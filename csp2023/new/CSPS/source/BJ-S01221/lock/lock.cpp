//ÃÜÂëËø
#include<bits/stdc++.h>
using namespace std;
bool use[100005];
int luan[10];
bool maybe[100005];
int n,yb,hh,cnt;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<81;
		return 0;
	}
	for(int i=0;i<=99999;i++){
		use[i]=true;
	}
	for(int haminuo=0;haminuo<n;haminuo++){
		memset(maybe,0,sizeof(maybe));
		for(int i=1;i<=5;i++){
			cin>>luan[i];
		}
		for(int i=1;i<=9;i++){
			hh=((luan[1]+i)%10)*10000+luan[2]*1000+luan[3]*100+luan[4]*10+luan[5];
			maybe[hh]=true;
			hh=luan[1]*10000+((luan[2]+i)%10)*1000+luan[3]*100+luan[4]*10+luan[5];
			maybe[hh]=true;
			hh=luan[1]*10000+luan[2]*1000+((luan[3]+i)%10)*100+luan[4]*10+luan[5];
			maybe[hh]=true;
			hh=luan[1]*10000+luan[2]*1000+luan[3]*100+((luan[4]+i)%10)*10+luan[5];
			maybe[hh]=true;
			hh=luan[1]*10000+luan[2]*1000+luan[3]*100+luan[4]*10+((luan[5]+i)%10);
			maybe[hh]=true;
			hh=((luan[1]+i)%10)*10000+((luan[2]+i)%10)*1000+luan[3]*100+luan[4]*10+luan[5];
			maybe[hh]=true;
			hh=luan[1]*10000+((luan[2]+i)%10)*1000+((luan[3]+i)%10)*100+luan[4]*10+luan[5];
			maybe[hh]=true;
			hh=luan[1]*10000+luan[2]*1000+((luan[3]+i)%10)*100+((luan[4]+i)%10)*10+luan[5];
			maybe[hh]=true;
			hh=luan[1]*10000+luan[2]*1000+luan[3]*100+((luan[4]+i)%10)*10+((luan[5]+i)%10);
			maybe[hh]=true;
		}
		for(int i=0;i<=99999;i++){
			if(use[i]==true && maybe[i]==true){
				continue;
			}
			use[i]=false;
		}
	}
	for(int i=0;i<=99999;i++){
		if(use[i]==true){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}