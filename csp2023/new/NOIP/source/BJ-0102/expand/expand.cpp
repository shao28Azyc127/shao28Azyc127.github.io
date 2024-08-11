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
const int N=2003;
int a[N],b[N],c[N],d[N];
bool f[N][N];
int n,m;
void solve(){
    if(a[1]+c[1]==b[1]+d[1]){
        putchar('0');
        return;
    }
    memset(f,0,sizeof(f));
    f[0][0]=1;
    if(a[1]+c[1]>b[1]+d[1]){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i]+c[i]>b[j]+d[j]&&(f[i-1][j-1]||f[i][j-1]||f[i-1][j])){
                    f[i][j]=1;
                }
            }
        }
        if(f[n][m])putchar('1');
        else putchar('0');
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i]+c[i]<b[j]+d[j]&&(f[i-1][j-1]||f[i][j-1]||f[i-1][j])){
                    f[i][j]=1;
                }
            }
        }       
        if(f[n][m])putchar('1');
        else putchar('0');
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int q,x,y,l,r;
    read(q),read(n),read(m),read(q);
    for(int i=1;i<=n;i++)read(a[i]);
    for(int i=1;i<=m;i++)read(b[i]);
    solve();
    for(int i=1;i<=q;i++){
        read(x),read(y);
        for(int j=1;j<=x;j++){
            read(l),read(r);
            c[l]=r-a[l];
        }
        for(int j=1;j<=y;j++){
            read(l),read(r);
            d[l]=r-b[l];
        }
        solve();
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
    }
    return 0;
}
