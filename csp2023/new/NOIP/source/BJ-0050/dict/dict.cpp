#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>void read(T &x){
	int f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=3020;
int n,m,p1,p2;
char c1,c2,c3;
string s[2][N],ss[20];
int c[120];
bool cmp1(int t1,int x,int t2,int y){
	for(int i=0;i<m;i++){
		if(s[t1][x][i]<s[t2][y][i]) return 1;
		if(s[t1][x][i]>s[t2][y][i]) return 0;
	}
	return 1;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++) c[j]=0;
		for(int j=1;j<=m;j++) cin>>c1,c[c1-'a'+1]++;
		for(int j=1;j<=26;j++)
			for(int z=1;z<=c[j];z++) s[0][i]+=j+'a'-1;
		for(int j=26;j>=1;j--)
			for(int z=1;z<=c[j];z++) s[1][i]+=j+'a'-1;
	}
	s[1][0]="z";s[1][0][0]++;
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	p1=0,p2=0;
	for(int i=1;i<=n;i++){
		if(cmp1(1,i,1,p1)) p2=p1,p1=i;
		else if(cmp1(1,i,1,p2)) p2=i;
	}
	for(int i=1;i<=n;i++){
		if(i!=p1) cout<<cmp1(0,i,1,p1);
		else cout<<cmp1(0,i,1,p2);
	}
	return 0;
}
/*
 * wow im here again!
 * 
 * the last official contest for me!
 * 
 * finally!
 * 
 * (sadly i wont get any prizes this time too)  
 */
