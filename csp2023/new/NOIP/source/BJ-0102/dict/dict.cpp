#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define spc putchar(' ')
#define Enter putchar('\n')
void read(int &number){
    bool f=0;
    number=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number=number*10+(ch^48);
        ch=getchar();
    }
    if(f)number=-number;
}
void lread(LL &number){
    bool f=0;
    number=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number=number*10+(ch^48);
        ch=getchar();
    }
    if(f)number=-number;
}
void print(LL number){
    if(number<0){
        putchar('-');
        number=-number;
    }
    if(number>=10){
        print(number/10);
    }
    putchar((number%10)^48);
}
const int N=3009;
char s[N][N],g[N][N]; 
inline bool cmp(char &x,char &y){
    return x>y;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    int mi=1;
    for(int i=1;i<=n;i++){
        scanf("%s ",s[i]+1);
        for(int j=1;j<=m;j++){
            g[i][j]=s[i][j];
        }
        sort(g[i]+1,g[i]+m+1,cmp);
        sort(s[i]+1,s[i]+m+1);
        if(mi<i){
            for(int j=0;j<m;j++){
                if(g[i][j]<g[mi][j]){
                    mi=i;
                    break;
                }
                if(g[i][j]>g[mi][j])break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i==mi)putchar('1');
        else{
            bool fl=0;
            for(int j=0;j<m;j++){
                if(s[i][j]<g[mi][j]){
                    fl=1;
                    break;
                }
                if(s[i][j]>g[mi][j])break;
            }
            print(fl);
        }
    }
    return 0;
}
