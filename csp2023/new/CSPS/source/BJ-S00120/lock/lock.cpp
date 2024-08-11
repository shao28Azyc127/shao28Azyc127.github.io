#include<bits/stdc++.h>
using namespace std;

bool yes[100010];
bool res[100010];

inline int toint(int x1,int x2,int x3,int x4,int x5){
	//printf("%d %d %d %d %d\n",x1,x2,x3,x4,x5);
	return x1*1+x2*10+x3*100+x4*1000+x5*10000;
}

int N;

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	memset(res,true,sizeof(res));
	scanf("%d",&N);
	while(N--){
	memset(yes,false,sizeof(yes));
	int x[6];
	for(int i=0;i<5;i++) scanf("%d",&x[i]);
	for(int i=0;i<5;i++){
		for(int j=1;j<10;j++){
			x[i]=(x[i]+1)%10;
			yes[toint(x[0],x[1],x[2],x[3],x[4])]=true;
		}
		x[i]=(x[i]+1)%10;
	}
	for(int i=0;i<4;i++){
		for(int j=1;j<10;j++){
			x[i]=(x[i]+1)%10;
			x[i+1]=(x[i+1]+1)%10;
			yes[toint(x[0],x[1],x[2],x[3],x[4])]=true;
		}
		x[i]=(x[i]+1)%10;
		x[i+1]=(x[i+1]+1)%10;
	}
	for(int i=0;i<100000;i++)
		res[i]=res[i]&&yes[i];
	}
	int cnt=0;
	for(int i=0;i<100000;i++)
		cnt+=res[i];
	printf("%d\n",cnt);
	return 0;
}