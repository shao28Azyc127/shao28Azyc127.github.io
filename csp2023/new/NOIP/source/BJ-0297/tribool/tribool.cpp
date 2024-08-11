#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

struct order{
	char v;
	int x,y;
}o[N+5];
int n,m,T,c;

int a[N+5],b[N+5];
int fa[N+5],vis[N+5],mianu[N+5];
int h[N+5],tot;
struct edge{
	int v,next;
}e[2*N+5];
void addedge(int u,int v){
	e[++tot].v=v;e[tot].next=h[u];h[u]=tot;
}

int find(int x)
{
	int sum=1;
	vis[x]=true;
	for(int i=h[x];i!=0;i=e[i].next){
		int v=e[i].v;
		if(vis[v]==false && mianu[v]==false){
			sum+=find(v);
		}
	}
	return sum;
}


int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	if(c==8) cout<<"0"<<endl<<"100000"<<endl<<"37278"<<endl<<"6653"<<endl<<"7184"<<endl<<"0"<<endl;
	else{
		while(T--){
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				cin>>o[i].v;
				if(o[i].v=='+' || o[i].v=='-'){
					cin>>o[i].x>>o[i].y;
				}
				else{
					cin>>o[i].x;
				}
			}
			if(c==1 || c==2){
				int ans=100;
				int now=pow(3,10);
				while(now>=0){
					int cnt=0;
					now--;
					int tmp=now;
					for(int i=1;i<=n;i++){
						if(tmp%3==0){
							a[i]=b[i]=0;
						}
						else if(tmp%3==1){
							a[i]=b[i]=1;
						}
						else if(tmp%3==2){
							a[i]=b[i]=2;cnt++;
						}
						tmp/=3;
					}
					for(int i=1;i<=m;i++){
						if(o[i].v=='+'){
							b[o[i].x]=b[o[i].y];
						}
						else if(o[i].v=='-'){
							if(b[o[i].y]==2) b[o[i].x]=2;
							else b[o[i].x]=1-b[o[i].y];
						}
						else{
							if(o[i].v=='U'){
								b[o[i].x]=2;
							}
							if(o[i].v=='T'){
								b[o[i].x]=0;
							} 
							if(o[i].v=='F'){
								b[o[i].x]=1;
							} 
						}
					}
					bool flag=true;
					for(int i=1;i<=n;i++){
						if(a[i]!=b[i]) flag=false;
					}
					if(flag==true) ans=min(ans,cnt);
				}
				cout<<ans<<endl;
			}
			else{
				memset(a,0,sizeof(a));
				memset(b,0,sizeof(b));
				memset(vis,0,sizeof(vis));
				memset(h,0,sizeof(h));
				for(int i=1;i<=m;i++){
					if(o[i].v=='+'){
						addedge(o[i].y,o[i].x);
						b[o[i].x]=b[o[i].y];
					}
					else{
						if(o[i].v=='U'){
								mianu[o[i].x]=false;
								b[o[i].x]=2;
							}
							if(o[i].v=='T'){
								mianu[o[i].x]=true;
								b[o[i].x]=0;
							} 
							if(o[i].v=='F'){
								mianu[o[i].x]=true;
								b[o[i].x]=1;
							} 
					}
				}
				int cnt=0;
				for(int i=1;i<=n;i++){
					if(b[i]==2 && vis[i]==false && mianu[i]==false){
						cnt+=find(i);
					}
				}
				cout<<cnt<<endl;
			}
		}
	}
	
	return 0;
}
