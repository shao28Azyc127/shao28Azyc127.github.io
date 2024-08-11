#include<bits/stdc++.h>
using namespace std;
int lock[49];int ans;int num=0;
int main(){
	int n;
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n*5;i++){
		cin>>lock[i];
		}
		if(n<=1){
		ans=5*9+4*9;
		}
		if(n==2){
			for(int i=1;i<=10;i++){
				if(i<=5&&lock[i]!=lock[i+5]){
				num++;
				}
				}
				ans=num*10;
			}
			if(n==3){
				for(int i=1;i<=15;i++){
				if(i<=10&&lock[i]!=lock[i+5]){
				num++;
				}
				}
				ans=num*10;
			}
				if(n==4){
				for(int i=1;i<=20;i++){
				if(i<=15&&lock[i]!=lock[i+5]){
				num++;
				}
				}
				ans=num*10;
			}
				if(n==5){
				for(int i=1;i<=25;i++){
				if(i<=20&&lock[i]!=lock[i+5]){
				num++;
				}
				}
				ans=num*10;
			}
				if(n==6){
				for(int i=1;i<=30;i++){
				if(i<=25&&lock[i]!=lock[i+5]){
				num++;
				}
				}
				ans=num*10;
			}	if(n==7){
				for(int i=1;i<=35;i++){
				if(i<=30&&lock[i]!=lock[i+5]){
				num++;
				}
				}
				ans=num*10;
			}
				if(n==8){
				for(int i=1;i<=40;i++){
				if(i<=35&&lock[i]!=lock[i+5]){
				num++;
				}
				}
				ans=num*10;
			}
		cout<<ans;
	return 0;
}