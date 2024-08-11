#include<iostream>
#include<algorithm>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=3005;
char s[N][N],asd[N][N],dsd[N][N];
int p[N],n,m;
bool cmp(int a,int b){
    for(int i=1;i<=m;++i)
        if(dsd[a][i]!=dsd[b][i])return dsd[a][i]<dsd[b][i];
    return 0;
}
bool cmG(int a,int b){
    for(int i=1;i<=m;++i)
        if(asd[a][i]<dsd[b][i])return 1;
    return 0;
}
bool cm(char a,char b){return a>b;}
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    rep(i,n)scanf("%s",s[i]+1);
    rep(i,n){
        p[i]=i;
        rep(j,m)asd[i][j]=dsd[i][j]=s[i][j];
        sort(asd[i]+1,asd[i]+1+m);sort(dsd[i]+1,dsd[i]+1+m,cm);
    }
    sort(p+1,p+1+n,cmp);
    rep(i,n){
        if(i==p[1]){
            if(n==1)putchar('1');
            else putchar(cmG(i,p[2])?'1':'0');
        }else putchar(cmG(i,p[1])?'1':'0');
    }
    return 0;
}
