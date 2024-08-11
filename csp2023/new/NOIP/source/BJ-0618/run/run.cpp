#include<bits/stdc++.h>
using namespace std;
int C,T;
long long n,m,k,d,ans;
struct prize{
	long long x,y,v;
};
stack<prize> przs;
void dfs(int date){
	
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
	    scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		ans=0;
	    long long x,y,v;
	    for(long long i = 1;i <= m;i++){
			scanf("%lld%lld%lld",&x,&y,&v);
			if(y<=k && v>y*d){
			    //przs.push({x,y,v});
			    ans+=v;
			    ans-=y*d;
		    }
		}
		printf("%lld\n",ans);
	}
	return 0;
}
