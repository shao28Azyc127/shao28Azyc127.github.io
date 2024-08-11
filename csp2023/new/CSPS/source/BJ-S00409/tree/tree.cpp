#include<iostream>
#include<cstdio>
using namespace std;
int main(){
int n,m,k;
int a,b,c;
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);
scanf("%d",&n);
int ans=0;
for(int i=1;i<=n;++i){scanf("%d%d%d",&a,&b,&c);ans=max(a,ans);}
printf("%d\n",ans);
return 0;
}