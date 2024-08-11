#include<iostream>
#include<fstream>
using namespace std;
typedef long long LL;
const int N=10010;
char s[N];
bool f[N][N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	scanf("%d%s",&n,s+1);
	LL ans=0;
	for(int len=2;len<=n;len+=2)
		for(int i=1,j=i+len-1;j<=n;i++,j++){
			if(s[i]==s[j]&&(len==2||f[i+1][j-1])){
				f[i][j]=1;
				ans++;
			}
			if(!f[i][j])
				for(int k=i+1;k<j-1;k+=2)
					if(f[i][k]&&f[k+1][j]){
						f[i][j]=1;
						ans++;
						break;
					}
		}
	printf("%lld",ans);
	return 0;
}