#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char s[N][N];
bool cmp(char x,char y){
    return x>y;
}
struct nd{
    int id;
    char s[N];
}all[N*2];
bool cmp2(nd x,nd y){
    for(int i=1;i<=m;i++){
        if(x.s[i]<y.s[i]) return 1;
        if(x.s[i]>y.s[i]) return 0;
    }
    return x.id>y.id;
}
int ans[N];
int main(){
  //  freopen("dat","r",stdin);

    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",all[i].s+1);
        sort(all[i].s+1,all[i].s+m+1,cmp);
        for(int j=1;j<=m;j++)
            all[i+n].s[j]=all[i].s[j];
        sort(all[i].s+1,all[i].s+m+1);
        all[i].id=i;
        all[i+n].id=i+n;
    }
    int nn=n*2;
    sort(all+1,all+nn+1,cmp2);
    for(int i=1;i<=nn;i++){
        if(all[i].id>n)
            break;
        ans[all[i].id]=1;
    }
    for(int i=1;i<=n;i++)
        printf("%d",ans[i]);
    return 0;
}
