#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,i,j,a[100010][3],minn=100010;
string sym="+-TFU",prex;
char u;

void dfs(int k,string ex,string nx){
	if(k>m){
		int sum=0;
		cout<<ex<<nx<<endl;
		for(int i=1;i<=n;i++){
			if(nx[i]=='0') nx[i]='T';
			if(ex[i]=='0') ex[i]=nx[i];
			if(ex[i]!=nx[i]) return;
			sum+=(ex[i]=='U') ;
		}
		//if(ex!=nx) return;
		if(sum<minn) minn=sum;
		return;
	}
	char u=sym[a[k][0]];
	i=a[k][1];
	if(u=='+'||u=='-') j=a[k++][2];
	string endx=ex,nowx=nx;
	switch(u){
		case '+':
			if(nx[j]=='0'){
				ex[j]='T'; nx[i]='T'; nx[j]='T'; dfs(k,ex,nx); ex=endx; nx=nowx;
				ex[j]='F'; nx[i]='F'; nx[j]='F'; dfs(k,ex,nx); ex=endx; nx=nowx;
				ex[j]='U'; nx[i]='U'; nx[j]='U'; dfs(k,ex,nx);
			}else{
				nx[i]=nx[j]; dfs(k,ex,nx); ex=endx; nx=nowx;
			}break;
		case '-':
			if(nx[j]=='0'){
				ex[j]='T'; nx[i]='F'; nx[j]='T'; dfs(k,ex,nx); ex=endx; nx=nowx;
				ex[j]='F'; nx[i]='T'; nx[j]='F'; dfs(k,ex,nx); ex=endx; nx=nowx;
				ex[j]='U'; nx[i]='U'; nx[j]='U'; dfs(k,ex,nx);
			}else{
				if(nx[j]=='U') nx[i]='U'; else nx[i]=(nx[j]=='T'?'F':'T'); dfs(k,ex,nx);
			}break;
		default:
			nx[i]=u;
	}
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	for(int ii=0;ii<t;ii++){
		prex="0";
		cin>>n>>m;
		for(int jj=1;jj<=m;jj++){
			cin>>u>>i;
			a[jj][0]=sym.find(u);
			if(u=='+'||u=='-'){
				cin>>j;
				a[jj][2]=j;
			}
			a[jj][1]=i;
		}
		for(int i=0;i<n;i++) prex+='0';
		dfs(1,prex,prex);
		cout<<minn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 3
- 2 1
- 3 2
+ 1 3
*/
