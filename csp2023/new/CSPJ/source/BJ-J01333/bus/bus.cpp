#include<bits/stdc++.h>
using namespace std;
int mmap[10005][10005];
int n,m,k,u,v,w;
struct node{
	int x,s1,s2;//位置，当前用时，出发时刻
};
queue<node>q;node s,t1;
int ans=-1,t;
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	memset(mmap,-1,sizeof(mmap));
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		mmap[u][v]=w;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<mmap[i][j]<<' ';
//	    }
//	    cout<<endl;
//	}
	q.push((node){1,0,0});
	while(!q.empty()){
		s=q.front();
		q.pop();
		if(s.x==n&&s.s1%k==0){
			if(s.s2+s.s1<ans||ans==-1){
				ans=s.s2+s.s1;
				continue;
			}
		}
		if(ans!=-1&&s.s1+s.s2>ans)continue;
		for(int i=1;i<=n;i++){
			if(mmap[s.x][i]!=-1){
				t1=s;
				if(mmap[s.x][i]>s.s1+s.s2){
					t=mmap[s.x][i]-s.s1+s.s2;
					if(t%k==0)t1.s2=t;
					else t1.s2=k*(t/k)+k;
					
				}
				t1.s1++;t1.x=i;
			    q.push(t1);	
			}
		}
	}
	cout<<ans;
	return 0;
}
