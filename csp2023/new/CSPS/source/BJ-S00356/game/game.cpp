#include<bits/stdc++.h>
using namespace std;
int n,z[260]={},zz[200005]={},zq[200005]={};long long ans=0;
char a[200005];
bool dfs(int x,int y,int cnt){
    if(cnt==0)return true;
    for(int i=x;i<y;i++){
        if(zz[i]!=-1&&zz[i]<=y&&a[i]==a[zz[i]]){
            zz[zq[i]]=zz[zz[i]];
            zq[zz[zz[i]]]=zq[i];
            zz[i]=-1;
            zz[zz[i]]=-1;
            return dfs(x,y,cnt-2);
        }
    }
    return false;
}
long long ok(int x,int y){
    for(int i=x;i<=y;i++)z[(int)a[i]]++;
    for(int i=0;i<=256;i++){
        if(z[i]%2==1)return 0;
    }
    for(int i=x;i<=y;i++)zz[i]=i+1,zq[i]=i-1;
    if(dfs(x,y,y-x+1))return 1;
    else return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d\n",&n);
    scanf("%s",a);
    if(n<=800){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                memset(z,0,sizeof(z));
                if((j-i+1)%2==1)continue;
                ans+=ok(i,j);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
