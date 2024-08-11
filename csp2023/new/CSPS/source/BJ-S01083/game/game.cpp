#include <bits/stdc++.h>
using namespace std;

#define gc getchar
#define pc putchar

inline int read(){
	int x=0; bool f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=0;
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return f?x:-x;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}

const int MAXN=2000005;
char s[MAXN];
int f[8005];
bitset<8005> g[8005];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,res=0;
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n<=8000){
		for(int i=2;i<=n;i++){
			if(s[i]==s[i-1]){
				g[i][i-1]=1;
				g[i]|=g[i-2];
			}
			for(int j=1;j<i-1;j++) g[i][j]=g[i][j]|(g[i-1][j+1] && s[j]==s[i]);
			for(int j=1;j<i-1;j++) if(g[i][j]) g[i]|=g[j-1];
			res+=g[i].count();
		}
		cout<<res;
	}else{

	}
	return 0;
}