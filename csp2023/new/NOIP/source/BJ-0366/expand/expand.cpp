#include<bits/stdc++.h>
#define pi(x) freopen(x,"r",stdin);
#define po(x) freopen(x,"w",stdout);
#define ci() fclose(stdin);
#define co() fclose(stdout);
using namespace std;
const int N=5e5+10;
int c,n,m,q;
int X[N],Y[N];
int tx[N],ty[N];
int p,v,kx,ky;
bool ans[N];
int cd=0;
bool solve1(int x[],int y[]){
	//~ for(int i=1;i<=n;i++){
		//~ cout<<x[i]<<" ";
	//~ }
	//~ cout<<endl;
	//~ for(int i=1;i<=m;i++){
		//~ cout<<y[i]<<" ";
	//~ }
	//~ cout<<endl<<endl;
	int lx=n;
	int ly=m;
	int maxx=-1,maxy=-1,minx=2e9,miny=2e9;
	if((x[1]-y[1])*(x[lx]-y[ly])<=0) return 0;   //性质一
	else{
		bool relas=(x[1]-y[1]<0);  
		for(int i=1;i<=lx;i++){
			maxx=max(maxx,x[i]);
			minx=min(minx,x[i]);
		}
		for(int i=1;i<=ly;i++){
			maxy=max(maxy,y[i]);
			miny=min(miny,y[i]);
		}
		if(relas!=(maxx-maxy<=0)) return 0;   //若两序列中最大值的大小关系和首尾大小关系不一致,则不存在
		if(relas!=(minx-miny<=0)) return 0;   //最小值同理，无法找到与其相匹的元素
		return 1;
	}
}
void solve(){
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>X[i];
	}
	for(int i=1;i<=m;i++){
		cin>>Y[i];
	}
	ans[++cd]=solve1(X,Y);
	//~ cout<<"extra datas:"<<endl;
	for(int i=1;i<=q;i++){
		cin>>kx>>ky;
		for(int j=1;j<=n;j++){
			tx[j]=X[j];
		}
		for(int j=1;j<=m;j++){
			ty[j]=Y[j];
		}
		for(int j=1;j<=kx;j++){
			cin>>p>>v;
			tx[p]=v;
		}
		for(int j=1;j<=ky;j++){
			cin>>p>>v;
			ty[p]=v;
		}
		ans[++cd]=solve1(tx,ty);
	}
	for(int i=1;i<=cd;i++) cout<<ans[i];
}

int main(){
	pi("expand.in");
	po("expand.out");
	ios::sync_with_stdio(false);
	solve();
	ci();
	co();
}
/*
my:1111011000010111010101010100101010110000000000111001011010000
ac:1101100011110101110101111111111111111110011111111101101100000

195982977 303897138 437154869 81559605 365511323 302808478
342942401 297976421 445071632 83871721 304067809 427239638

950087990 922968889 880355772 966742067 834991722 909678381 
918655047 930778126 791681101 956185939 941339699 845896874 

*/
