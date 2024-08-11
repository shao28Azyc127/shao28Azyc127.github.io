#include<bits/stdc++.h>
using namespace std;
int n,m,a[3003][3003];
char x[3003];
bool cmp(int a,int b){return a>b;}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=n;++i){
        cin>>x;
        for(register int j=0;j<m;++j)a[i][j]=x[j]-'a';
    }
    if(n==1)return printf("1\n"),0;
    for(register int i=1;i<=n;++i)sort(a[i],a[i]+m,cmp);
    for(register int i=1;i<=n;++i){
        bool flag=1;
        for(register int j=1;j<=n;++j){
            if(j==i)continue;
            if(a[i][m-1]>=a[j][0]){flag=0;break;}
        }
        if(flag)printf("1");
        else printf("0");
    }
    return 0;
}
