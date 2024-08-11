#include<cstdio>
using namespace std;
const int MAXN=3010;
char s[MAXN][MAXN];
int a[MAXN][26],mi[MAXN],mx[MAXN];
int read(){
    int num=0,sign=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    return num*sign;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++) scanf("\n%s",s[i]);
    for(int i=1;i<=n;i++) for(int j=0;j<m;j++)
        a[i][s[i][j]-'a']++;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++) if(a[i][j]){mi[i]=j;break;}
        for(int j=25;j>=0;j--) if(a[i][j]){mx[i]=j;break;}
    }
    for(int i=1;i<=n;i++){
        int ans=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(mi[i]>=mx[j]) ans=0;
        }
        printf("%d",ans);
    }
    printf("\n");
    return 0;
}