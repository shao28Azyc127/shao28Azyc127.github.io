#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[10][10][10][10][10][10];
int a[10];
void dfs(int a,int b,int c,int d,int e,int pos){
    vis[pos][a][b][c][d][e]=1;
}
int main(){
    #ifndef JZQ
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int pos=1;pos<=n;pos++){
        int a,b,c,d,e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        for(int i=1;i<=9;i++){
            dfs((a+i)%10,b,c,d,e,pos);
            dfs(a,(b+i)%10,c,d,e,pos);
            dfs(a,b,(c+i)%10,d,e,pos);
            dfs(a,b,c,(d+i)%10,e,pos);
            dfs(a,b,c,d,(e+i)%10,pos);
            dfs((a+i)%10,(b+i)%10,c,d,e,pos);
            dfs(a,(b+i)%10,(c+i)%10,d,e,pos);
            dfs(a,b,(c+i)%10,(d+i)%10,e,pos);
            dfs(a,b,c,(d+i)%10,(e+i)%10,pos);
        }
    }
    int ans=0;
    for(int a=0;a<=9;a++) for(int b=0;b<=9;b++) for(int c=0;c<=9;c++) for(int d=0;d<=9;d++) for(int e=0;e<=9;e++){
        bool flag=1;
        for(int i=1;i<=n;i++){
            flag=flag&&vis[i][a][b][c][d][e];
        }
        if(flag) ans++;
    }
    printf("%d",ans);
    return 0;
}