#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=2e5+10;
char s[MAXN];
vector<int> f[MAXN];
int read(){
    int num=0,sign=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    return num*sign;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n=read(),m=sqrt(512000000/n),ans=0;scanf("\n%s",s+1);
    if(m>n) m=n;
    for(int i=1;i<=n;i++) f[i].push_back(1);
    for(int j=1;j<=m;j++) for(int i=1;i<n&&i+j*2-1<=n;i++){
        f[i].push_back(f[i+1][j-1]&&s[i]==s[i+j*2-1]);
        if(!f[i][j]) for(int k=1;k<j;k++)
            f[i][j]|=f[i][k]&&f[i+k*2][j-k];
        ans+=f[i][j];
    }
    printf("%d\n",ans);
    return 0;
}