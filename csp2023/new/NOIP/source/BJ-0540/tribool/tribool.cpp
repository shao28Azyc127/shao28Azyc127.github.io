#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int c,T;
int n,m;
int id[300010],num[300010],ednum[500010],vis[500010],tmpvis[500010],sum[500010],cnt,tcnt;
int trinot(int x){
	if(x==1) return 2;
	if(x==2) return 1;
	if(x==3) return 3;
	return 0;
}
int trinot2(int x){
	if(x>n) return x-n;
	else return x+n;
}
struct node{
	int val,to;
};
vector<node> edge[500010];
vector<int> pas[500010];
void dfs1(int x,int fa,int k){
	vis[x]=k;
	for(int i=0;i<ednum[x];i++){
		int y=edge[x][i].to;
		if(y==fa) continue;
		if(edge[x][i].val==1) dfs1(y,x,k);
		if(edge[x][i].val==2) dfs1(y,x,trinot(k));
	}
}
void dfs2(int x,int fa,int k){
	//cout<<x;
	tmpvis[x]=k;
	for(int i=0;i<ednum[x];i++){
		//cout<<1;
		int y=edge[x][i].to;
		if(y==fa) continue;
		if(edge[x][i].val==1) dfs2(y,x,k);
		if(edge[x][i].val==2) dfs2(y,x,trinot2(k));
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("trebool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		memset(pas,0,sizeof(pas));
		memset(edge,0,sizeof(edge));
		memset(id,0,sizeof(id));
		memset(ednum,0,sizeof(ednum));
		memset(vis,0,sizeof(vis));
		memset(tmpvis,0,sizeof(tmpvis));
		memset(sum,0,sizeof(sum));
		scanf("%d%d",&n,&m);
		cnt=n;tcnt=0;
		for(int i=1;i<=n;i++){
			pas[i].push_back(i);
			id[i]=i;
			num[i]=0;
		}
		char op;
		node tmp;
		int x,y;
		for(int i=1;i<=m;i++){
			cin>>op;
			if(op=='T'){
				scanf("%d",&x);
				id[++cnt]=x;pas[x].push_back(cnt);++num[x];
				tmp.to=cnt,tmp.val=1;
				edge[400001].push_back(tmp);
				ednum[400001]++;
			}
			if(op=='F'){
				scanf("%d",&x);
				id[++cnt]=x;pas[x].push_back(cnt);++num[x];
				tmp.to=cnt,tmp.val=1;
				edge[400002].push_back(tmp);
				ednum[400002]++;
			}
			if(op=='U'){
				scanf("%d",&x);
				id[++cnt]=x;pas[x].push_back(cnt);++num[x];
				tmp.to=cnt,tmp.val=1;
				edge[400003].push_back(tmp);
				ednum[400003]++;
			}
			if(op=='+'){
				scanf("%d%d",&x,&y);
				id[++cnt]=x;pas[x].push_back(cnt);++num[x];
				tmp.to=cnt,tmp.val=1;
				edge[pas[y][num[y]]].push_back(tmp);
				ednum[pas[y][num[y]]]++;
			}
			if(op=='-'){
				scanf("%d%d",&x,&y);
				id[++cnt]=x;pas[x].push_back(cnt);++num[x];
				tmp.to=cnt,tmp.val=2;
				edge[pas[y][num[y]]].push_back(tmp);
				ednum[pas[y][num[y]]]++;
			}
		}
		dfs1(400001,0,1);
		dfs1(400002,0,2);
		dfs1(400003,0,3);
		for(int i=1;i<=cnt;i++){
			if(vis[i]) tmpvis[i]=2*n+vis[i];
			else if(i<=n) tmpvis[i]=i;
		}
		sum[2*n+3]=1;
		for(int i=1;i<=n;i++) dfs2(i,0,tmpvis[i]);
		for(int i=1;i<=n;i++){
			//cout<<tmpvis[pas[i][0]]<<" "<<tmpvis[pas[i][num[i]]]<<endl;
			if(tmpvis[pas[i][num[i]]]==2*n+3){
				sum[tmpvis[pas[i][0]]]=1,tcnt++;
				
			}
			if(tmpvis[pas[i][0]]==2*n+3) sum[tmpvis[pas[i][0]]]=1,tcnt++;
			if(tmpvis[pas[i][0]]+n==tmpvis[pas[i][num[i]]]){
				sum[tmpvis[pas[i][0]]]=1;sum[tmpvis[pas[i][0]]]=1,tcnt++;
			}
			if(sum[tmpvis[pas[i][num[i]]]]) sum[tmpvis[pas[i][0]]]=1,tcnt++;
			if(sum[tmpvis[pas[i][0]]]) sum[tmpvis[pas[i][num[i]]]]=1,tcnt++;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(tmpvis[pas[i][num[i]]]==2*n+3){
					sum[tmpvis[pas[i][0]]]=1;	
				}
				if(tmpvis[pas[i][0]]==2*n+3) sum[tmpvis[pas[i][0]]]=1;
				if(tmpvis[pas[i][0]]+n==tmpvis[pas[i][num[i]]]){
					sum[tmpvis[pas[i][0]]]=1;sum[tmpvis[pas[i][0]]]=1;
				}
				if(sum[tmpvis[pas[i][num[i]]]]) sum[tmpvis[pas[i][0]]]=1;
				if(sum[tmpvis[pas[i][0]]]) sum[tmpvis[pas[i][num[i]]]]=1;
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++) if(sum[tmpvis[pas[i][0]]]||sum[tmpvis[pas[i][num[i]]]]) flag+=1;
		printf("%d\n",flag);
	}
	return 0;
}
