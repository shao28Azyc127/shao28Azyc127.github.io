#include<iostream>
using namespace std;
int n;
int state[10][10];
bool vis[5]={0},flag2=0;
int cnt=0,flag,flag1;
int main(){
	freopen("lock.in","r",stdin);
 	freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++)cin>>state[i][j];
    }
    for(int i=1;i<n;i++){
		for(int j=0;j<5;j++){
			if(!vis[j]&&state[i][j]!=state[i-1][j]){
				cnt++;vis[j]=1;
			}
		}
    }
    if(cnt>2)cout<<0;
    if(cnt<1)cout<<81;
    if(cnt==1){
		if(n==2)cout<<10;
		else cout<<10-n;
	}
	if(cnt==2){
		for(int i=0;i<4;i++){
			if(vis[i]){
				if(!vis[i+1]){
					if(n<=2)cout<<2;
					else cout<<0;
				}
				else{
					flag=state[0][i]-state[0][i+1];
					if(state[0][i]>state[0][i+1])flag1=1;else flag1=0;
					for(int j=1;j<n;j++){
					    if(flag1&&state[j][i]<state[j][i+1])state[j][i]+=10;
					    if(!flag1&&state[j][i]>state[j][i+1])state[j][i+1]+=10;
					    if(state[j][i]-state[j][i+1]!=flag){flag2=1;break;}
					}
					if(flag2){if(n<=2)cout<<2;else cout<<0;}
					else {if(n<=2)cout<<12-n;else cout<<10-n;}
				}
			}
		}
	}
    return 0;
}
