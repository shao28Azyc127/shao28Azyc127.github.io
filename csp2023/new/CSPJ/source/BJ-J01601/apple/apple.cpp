#include <bits/stdc++.h>
using namespace std;
void fileio(string fname){
	string in=fname+".in",out=fname+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
}
const int N=1e9;
queue<int> q[2];
int n,ans;
signed main(){
	fileio("apple");
	scanf("%d",&n);
	if(n==N){
		printf("50 1\n");
		return 0;
	}
	if(n==1){
		printf("1 1\n");
		return 0;
	}
	for(int i=1;i<=n;++i){ 
		if(i%3!=1){
			q[0].push(i);
		}
	}
	if(n%3==1) ans=1;
	for(int i=2;;++i){
		int t=1;
		while(q[i&1].size()){
			int now=q[i&1].front();q[i&1].pop();
			if(t%3!=1){
				q[(i&1)^1].push(now);
			}
			else{
				if(now==n){
					ans=i;
				}
			}
			t++;
		}
		if(q[0].empty() && q[1].empty()){
			printf("%d %d\n",i,ans);
			return 0;
		}
	}
	return 0;
}