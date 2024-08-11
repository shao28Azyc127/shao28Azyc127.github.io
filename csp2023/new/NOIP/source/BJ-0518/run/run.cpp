#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

struct gift{
	long long x,y,v;
}g[100005];

int c,t;
long long n,m,k,d;
int st[100005];

bool cmp(gift a,gift b){
	return a.v>b.v;
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans,cnt=1;
		bool flag;
		memset(g,0,sizeof(g));
		
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>g[i].x>>g[i].y>>g[i].v;
			g[i].v-=(g[i].y*d);
			if(g[i].y>k||g[i].x-g[i].y<0){
				i--;
				m--;
			}
		}
		sort(g+1,g+m+1,cmp);
		ans=g[1].v;
		st[1]=g[1].x-g[1].y;
		for(int i=2;i<=m;i++){
			for(int j=1;j<=cnt;j++){
				if(g[i].x-st[j]<=k||g[i].x-g[i].y>=g[i-1].x
				||g[i].x<st[j]) flag=true;
				else flag=false;
			}
			if(flag){
				st[++cnt]=g[i].x-g[i].y;
				ans+=g[i].v;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
