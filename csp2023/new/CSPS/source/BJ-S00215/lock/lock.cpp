#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{
	const int N=10;
	int n,a[N][6],ans,nw[6];
	inline bool check(int val){
		nw[1]=val/10000,nw[2]=val%10000/1000,nw[3]=val%1000/100,nw[4]=val%100/10,nw[5]=val%10;
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=1;j<=5;j++)	if(a[i][j]!=nw[j])	cnt++;
			if(!cnt||cnt>2)	return 0;
			else if(cnt==2){
				if(a[i][1]!=nw[1]&&a[i][5]!=nw[5])	return 0;
				for(int j=2;j<5;j++)
					if(nw[j]!=a[i][j]){
						int c=(nw[j]-a[i][j]+10)%10;
						int cl=(nw[j-1]-a[i][j-1]+10)%10,cr=(nw[j+1]-a[i][j+1]+10)%10;
						if(!cl&&!cr)	return 0;
						else if(cl){
							if(cl!=c)	return 0;
						}else{
							if(cr!=c)	return 0;
						}
					}
			}
		}return 1;
	}
	int main(){
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=1;j<=5;j++)cin>>a[i][j];
		for(int i=0;i<100000;i++)	ans+=check(i);
		cout<<ans;
		return 0;
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return SOLUTION::main();
}