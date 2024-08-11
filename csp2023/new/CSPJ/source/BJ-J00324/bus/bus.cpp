#include<bits/stdc++.h>
using namespace std;
int ma[20050][20050],ans[20050];
int n,m,k;
bool res[10050];
void bfs(){
	queue<int>q;
	q.push(1);
	while(!q.empty()){
		int num=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(ma[num][i]!=0 && res[i]!=1){
				if(i==n)return ;
				else {
					q.push(i);
					ans[i]=ans[num]+1;
				}
			}
		}
	}
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int u,v,p;
		scanf("%d%d%d",&u,&v,&p);
		ma[u][v]=p;    
	}
	bfs();
	printf("%d",ans[n]);
    return 0;
}
