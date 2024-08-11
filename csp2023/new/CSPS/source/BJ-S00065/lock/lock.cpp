#include<iostream>
#include<fstream>
using namespace std;
const int N=20;
int n;
int a[N][N];
inline int get(int state,int x){
	for(int i=1;i<5-x+1;i++)
		state/=10;
	return state%10;
}
inline int turn(int a,int b){
	if(a<b)
		a+=10;
	return a-b;
}
inline bool check(int state){
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=5;j++)
			if(get(state,j)==a[i][j])
				cnt++;
		if(cnt==5)
			return 0;
		else if(cnt==4)
			continue;
		else if(cnt==3){
			bool flag=1;
			for(int j=1;j<5;j++)
				if(get(state,j)!=a[i][j]&&get(state,j+1)!=a[i][j+1])
					if(turn(get(state,j),a[i][j])==turn(get(state,j+1),a[i][j+1]))
						flag=0;
			if(!flag)
				continue;
		}
		return 0;
	}
	//printf("%d\n",state);
	return 1;
}
int main(){
	/*for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++)
			printf("%d ",turn(i,j));
		puts("");
	}*/
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			scanf("%d",&a[i][j]);
	int ans=0;
	for(int state=0;state<=99999;state++)
		if(check(state))
			ans++;
	printf("%d",ans);
	return 0;
}