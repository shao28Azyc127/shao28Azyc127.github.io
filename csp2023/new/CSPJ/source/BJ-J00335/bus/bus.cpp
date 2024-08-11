#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
vector<int> h[N];
vector<int> w[N];
int n,m,k,ans=0x3f3f3f3f;

void dfs(int u,int a){
	if(u==n){
		if(a%k!=0) return;
		ans=min(ans,a);
		return;
	}
	for(int i=0;i<h[u].size();i++){
		if(a<w[u][i]) continue;
		dfs(h[u][i],a+1);
	}
}

int main(){
	clock_t c = clock();
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	//freopn("bus.in","r",stdin);
	//freopen("bus.out","w",stdout);
	//freopen("bus.out","r",stdout);
	//freopen("bus.in","w",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,a;
		scanf("%d%d%d",&u,&v,&a);
		h[u].push_back(v);
		w[u].push_back(a);
	}
	
	dfs(1,k);
	//tnd why the start time can change????
	//has CSP-J had graph problem??? (except 2019)
	//...
	//30pts is enough
	//guess this problem in luogu is a green/blue problem
	//but i don't solve it

	//why T1 is so hard???
	//I think i can only get 90pts

	//T2 is easy Ì°ÐÄ
	//T3 is not very hard
	//it's only need to write 1.5KB code
	//...

	//When you see this, it's means i code can be in "ÆæÝâ´úÂë"?
	//Don't need to hide my username.

	//Luogu @mxdyzmx codeforces @mxdyzmx
	//xht Orz Orz Orz
	//kkk Orz Orz Orz
	//Ð¡·ÛÍÃ Orz Orz Orz
	//while(!csp.end()) rp++;
	//while(!csp.start()) rp++;
 	printf("%d",ans==0x3f3f3f3f?-1:ans);
	return 0;
}

/*
IAKIOI RP++(){
	while(I.age<18){
		while(!csp.start()) rp++;
		while(!csp.end()) rp++;
	}
	rp++;
	//dream time!
	while(!I.AKIOI()) rp=abs(rp)*abs(rp);
}

-------
|  |  |
|  |  |
| whk |
|     |
|     |
-------

*/