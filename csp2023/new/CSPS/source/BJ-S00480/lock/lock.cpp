#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<iostream>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define dF(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
int read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int maxn=141141;
int g[10][10],p[10];
void fre(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
}
int dis(int x,int y){
	if(x<y) return y-x;
	return y+10-x;
}
bool check(int i){
	int cnt=0;
	F(j,1,5) if(p[j]==g[i][j]) cnt++;
	if(cnt!=3&&cnt!=4) return 0;
	if(cnt==3){
		vector<int>pos;
		F(j,1,5) if(p[j]^g[i][j]) pos.pb(j);
		if(pos[0]!=pos[1]-1) return 0;
		int x=pos[0],y=pos[1];

		//return 0;
		return dis(p[x],g[i][x])==dis(p[y],g[i][y]);
 	}
	if(cnt==4) return 1;
}
signed main(){
	fre();
	int n=read(),ans=0;
	F(i,1,n) F(j,1,5) g[i][j]=read();
	F(a,0,9) F(b,0,9) F(c,0,9) F(d,0,9) F(e,0,9){
		p[1]=a,p[2]=b,p[3]=c,p[4]=d,p[5]=e;
		bool fl=0;
		F(i,1,n) if(!check(i)) fl=1;
		if(!fl) ans++;
	}
	printf("%d",ans);
}