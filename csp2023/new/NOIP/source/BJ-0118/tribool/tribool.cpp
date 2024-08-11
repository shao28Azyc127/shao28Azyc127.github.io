#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int f[N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int n,m,ans;
bool fl[N];
char c[N],p[N],cc[N];
int x[N],y[N];
char getfan(char c){
    if(c=='T')return 'F';
    if(c=='F')return 'T';
    return 'U';
}
bool ck(){
	for(int i=1;i<=n;i++)cc[i]=c[i];
	for(int i=1;i<=m;i++){
		if(p[i]=='+')cc[x[i]]=cc[y[i]];
		else if(p[i]=='-')cc[x[i]]=getfan(cc[y[i]]);
		else cc[x[i]]=p[i];
	}
	for(int i=1;i<=n;i++)if(cc[i]!=c[i])return 0;
	return 1;
}
void dfs(int x){
	if(x==n){
		int cnt=0;for(int i=1;i<=n;i++)if(c[i]=='U')cnt++;
		//cout<<cnt<<'\n';
		//for(int i=1;i<=n;i++)cout<<c[i]<<' ';
		//cout<<'\n';
		if(cnt>=ans)return ;
		if(ck()){
			ans=cnt;
			//cout<<cnt<<'\n';
			//for(int i=1;i<=n;i++)cout<<c[i]<<' ';
			//cout<<'\n';
		}
		return ;
	}
	c[x+1]='T';dfs(x+1);
	c[x+1]='F';dfs(x+1);
	c[x+1]='U';dfs(x+1);
}
void solve1(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
		cin>>p[i];
		if(p[i]=='+'||p[i]=='-')cin>>x[i]>>y[i];
		else cin>>x[i];
	}
    ans=n;
    dfs(0);
    cout<<ans<<'\n';
}
void solve2(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)c[i]='T';
    for(int i=1;i<=m;i++){
		cin>>p[i]>>x[i];c[x[i]]=p[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(c[i]=='U')ans++;
	cout<<ans<<'\n';
}
void solve3(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)c[i]='T',f[i]=i;
    for(int i=1;i<=m;i++){
		cin>>p[i];
		if(p[i]=='U'){
			cin>>x[i];
			f[x[i]]=x[i];c[x[i]]='U';
		}else{
			cin>>x[i]>>y[i];
			f[x[i]]=find(y[i]);
		}
	}
	for(int i=1;i<=m;i++){
		if(p[i]=='U'){
			c[x[i]]='U';
		}else{
			c[x[i]]=c[y[i]];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(c[i]=='U'||c[find(i)]=='U')ans++;
	}
	cout<<ans<<'\n';
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,T;scanf("%d%d",&C,&T);
    if(C==1||C==2){while(T--)solve1();return 0;}
    if(C==3||C==4){while(T--)solve2();return 0;}
    while(T--)solve3();
    return 0;
}
