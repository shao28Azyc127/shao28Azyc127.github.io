#include<bits/stdc++.h>
using namespace std;
int x[500005];
int y[500005];
bool dp[2005][2005];
bool check2(int n,int m){
	int max_=0,min_=0x7fffffff;
	for(int i=1;i<=n;i++){
		max_=max(max_,x[i]);
	}
	for(int i=1;i<=m;i++){
		min_=min(min_,y[i]);
	}
	if(x[1]<min_&&y[m]>max_){
		return true;
	}else{
		return false;
	}
}
bool check(int n,int m){
	if(n>2000||m>2000){
		return check2(n,m);
	}
	bool cmp=(x[1]>y[1]?true:false);
	//cout<<cmp<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=false;
		}
	}
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			//cout<<i<<' '<<j<<'|'<<dp[i][j]<<endl;
			if(dp[i][j]==false){
				continue;
			}
			if(cmp==true){
				if(i!=0&&x[i]>y[j+1]){
					dp[i][j+1]=true;
				}
				if(x[i+1]>y[j+1]){
					dp[i+1][j+1]=true;
				}
				if(j!=0&&x[i+1]>y[j]){
					dp[i+1][j]=true;
				}
			}else{
				if(i!=0&&x[i]<y[j+1]){
					dp[i][j+1]=true;
				}
				if(x[i+1]<y[j+1]){
					dp[i+1][j+1]=true;
				}
				if(j!=0&&x[i+1]<y[j]){
					dp[i+1][j]=true;
				}
			}
		}
	}
	return dp[n][m];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=m;i++){
		cin>>y[i];
	}
	cout<<check(n,m);
	queue<pair<int,int>> qx,qy;
	for(int i=1;i<=q;i++){
		int kx,ky;
		cin>>kx>>ky;
		for(int j=1;j<=kx;j++){
			int p,v;
			cin>>p>>v;
			qx.push({p,x[p]});
			x[p]=v;
		}
		for(int j=1;j<=ky;j++){
			int p,v;
			cin>>p>>v;
			qy.push({p,y[p]});
			y[p]=v;
		}
		/*
		for(int j=1;j<=n;j++){
			cout<<x[j]<<' ';
		}
		cout<<endl;
		for(int j=1;j<=m;j++){
			cout<<y[j]<<' ';
		}
		cout<<endl;
		*/
		cout<<check(n,m);
		while(!qx.empty()){
			x[qx.front().first]=qx.front().second;
			qx.pop();
		}
		while(!qy.empty()){
			y[qy.front().first]=qy.front().second;
			qy.pop();
		}
	}
}
/*
4 6 6 1
195982977 303897138 437154869 81559605 365511323 302808478
342942401 297976421 445071632 83871721 304067809 427239638
6 6
1 588505924
3 600919013
4 587707447
2 572576439
6 591139329
5 573288617
1 578277016
5 591213504
2 598714107
4 587825836
6 564344344
3 557004829


*/