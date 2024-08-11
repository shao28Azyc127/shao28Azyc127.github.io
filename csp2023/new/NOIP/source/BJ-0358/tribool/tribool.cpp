#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int isf[N],ex[N],d[N],vis[N],_,T,n,m,x,y,pth[N],ans;
char c;
vector<int> v[N],f[N];
queue<int> q;
int calc(int t,int i){
	if(v[t][i]<0){
		v[t][i]=-v[t][i];
		if(ex[t]>(-3)) return (-3)-ex[t];
		else return -3;
	}else return ex[t];
}
int calc2(int t,int i){
	if(f[t][i]<0){
		f[t][i]=-f[t][i];
		if(ex[t]>(-3)) return (-3)-ex[t];
		else return -3;
	}else return ex[t];
}
void Solve(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++) d[i]=0,ex[i]=i,isf[i]=0,vis[i]=0,v[i].clear(),f[i].clear();
	for(int i=1;i<=m;i++){
		cin>>c>>x;
		if(c=='T') isf[x]=0,ex[x]=-1;
		if(c=='F') isf[x]=0,ex[x]=-2;
		if(c=='U') isf[x]=0,ex[x]=-3;
		if(c=='-') cin>>y,isf[x]=(-1)-isf[y],ex[x]=ex[y];
		if(c=='+') cin>>y,isf[x]=isf[y],ex[x]=ex[y];
	}
	for(int i=1;i<=n;i++){
		if(isf[i]==0) isf[i]=1;
		if(ex[i]<0) q.push(i);
		else if(ex[i]==i){
			if(isf[i]==-1) ex[i]=-3,q.push(i);
			else ex[i]=-1,q.push(i);
		}
		else v[ex[i]].push_back(i*isf[i]),f[i].push_back(ex[i]*isf[i]),d[ex[i]]++;
	}
	while(!q.empty()){
		int t=q.front(); 
		q.pop();
		if(ex[t]==-3) ans++;
		for(int i=0;i<v[t].size();i++){
			int tmp=calc(t,i);
			ex[v[t][i]]=tmp;
			q.push(v[t][i]);
		}
	}
	for(int i=1;i<=n;i++) if(ex[i]>=0 && !d[i]){
		ex[i]=-1;q.push(i);vis[i]=i;
		int suc=1,cnt=0;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			pth[++cnt]=t;
			for(int j=0;j<f[t].size();j++){
				int tmp=calc2(t,j);
				if(ex[f[t][j]]<0){
					if(vis[f[t][j]]==i && tmp!=ex[f[t][j]]) suc=0;
					else if(vis[f[t][j]]!=i && ex[f[t][j]]==-3) suc=0;
					continue;
				}
				ex[f[t][j]]=tmp;
				vis[f[t][j]]=i;
				q.push(f[t][j]);
			}
		}
		if(suc==0){
			for(int i=1;i<=cnt;i++) ex[pth[i]]=-3;
			ans+=cnt;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T>>_;while(_--) Solve();
	return 0;
}
