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

struct Node{
	int b[6];
}a[9];

int cnt[11][11][11][11][11];
bool vis[11][11][11][11][11];

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) a[i].b[j]=read();
	for(int i=1;i<=n;i++){
		Node u=a[i];
		for(int j=1;j<=5;j++){
			for(int t=1;t<10;t++){
				u.b[j]=(u.b[j]+t)%10;
				vis[u.b[1]][u.b[2]][u.b[3]][u.b[4]][u.b[5]]=1;
				u.b[j]=(u.b[j]-t+10)%10;
			}
		}
		for(int j=1;j<5;j++){
			for(int t=1;t<10;t++){
				int k=j+1;
				u.b[j]=(u.b[j]+t)%10;
				u.b[k]=(u.b[k]+t)%10;
				vis[u.b[1]][u.b[2]][u.b[3]][u.b[4]][u.b[5]]=1;
				u.b[j]=(u.b[j]-t+10)%10;
				u.b[k]=(u.b[k]-t+10)%10;
			}
		}
		for(int v=0;v<10;v++)
		for(int w=0;w<10;w++)
		for(int x=0;x<10;x++)
		for(int y=0;y<10;y++)
		for(int z=0;z<10;z++) cnt[v][w][x][y][z]+=vis[v][w][x][y][z],vis[v][w][x][y][z]=0;
	}

	int res=0;
	for(int v=0;v<10;v++)
	for(int w=0;w<10;w++)
	for(int x=0;x<10;x++)
	for(int y=0;y<10;y++)
	for(int z=0;z<10;z++){
		if(cnt[v][w][x][y][z]==n) res++;
	}
	write(res);
	return 0;
}