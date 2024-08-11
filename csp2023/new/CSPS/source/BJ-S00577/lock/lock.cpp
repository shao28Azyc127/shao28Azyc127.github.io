#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 10
int n,cas[MAXN][MAXN],now[MAXN],f[MAXN],ans,dif[MAXN];
bool same(){
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=5;j++){
            if(cas[i][j]!=now[j]) flag=0;
        }
        if(flag) return 1;
    }
    return 0;
}
bool check(int id){
    for(int i=1;i<=5;i++){
        dif[i]=f[i]-cas[id][i];
        if(dif[i]<0) dif[i]+=10;
    }
    int pos=0;
    for(int i=1;i<=5;i++){
        if(dif[i]){
            if(pos==2) return 0;
            if(pos&&i>1&&(!dif[i-1]||(dif[i-1]&&dif[i-1]!=dif[i]))) return 0;
            pos++;
        }
    }
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++) scanf("%d",&cas[i][j]);
    }
    for(int a=0;a<=9;a++){
        now[1]=a;
        for(int b=0;b<=9;b++){
            now[2]=b;
            for(int c=0;c<=9;c++){
                now[3]=c;
                for(int d=0;d<=9;d++){
                    now[4]=d;
                    for(int e=0;e<=9;e++){
                        now[5]=e;
                        if(same()) continue;
                        for(int i=1;i<=5;i++) f[i]=now[i];
                        bool flag=1;
                        for(int i=1;i<=n&&flag;i++) if(!check(i)) flag=0;
                        ans+=flag;
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}