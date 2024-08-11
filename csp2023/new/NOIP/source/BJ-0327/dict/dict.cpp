#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3010;
int n,m;
char mn[N];
char s[N][N];
char t[N][N];
bool noip(char x,char y){return x>y;}
bool cmp(int id){
    for(int i=1;i<=m;i++){
        if(t[id][i]<mn[i]) return true;
        if(t[id][i]>mn[i]) return false;
    }
    return false;
}
bool cmp2(int id){
    for(int i=1;i<=m;i++){
        if(s[id][i]<mn[i]) return true;
        if(s[id][i]>mn[i]) return false;
    }
    return false;
}
void cpy(int id){
    for(int i=1;i<=m;i++) mn[i]=t[id][i];
}
bool flag;
int mid;
char cmn[N];
bool cmp3(int id){
    for(int i=1;i<=m;i++){
        if(t[id][i]<cmn[i]) return true;
        if(t[id][i]>cmn[i]) return false;
    }
    return false;
}
void cpy2(int id){
    for(int i=1;i<=m;i++) cmn[i]=t[id][i];
}
bool cmp4(int id){
    for(int i=1;i<=m;i++){
        if(s[id][i]<cmn[i]) return true;
        if(s[id][i]>cmn[i]) return false;
    }
    return false;
}
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)  t[i][j]=s[i][j];
    for(int i=1;i<=n;i++) sort(s[i]+1,s[i]+m+1),sort(t[i]+1,t[i]+m+1,noip);
    //for(int i=1;i<=n;i++) printf("%s\n",t[i]+1);
    for(int i=1;i<=n;i++){
        if(!flag||cmp(i)) cpy(i),flag=true,mid=i;
    }
    flag=false;
    for(int i=1;i<=n;i++){
        if(i!=mid&&(!flag ||cmp3(i)))  cpy2(i),flag=true;
    }
    //printf("%s\n",mn+1);
    for(int i=1;i<=n;i++){
        if(i!=mid){
            if(cmp2(i)) printf("1");
            else printf("0");
        }
        else{
            if(cmp4(i)) printf("1");
            else printf("0");
        }
    }
    printf("\n");
}
