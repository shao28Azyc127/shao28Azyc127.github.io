#include<bits/stdc++.h>

using namespace std;

const int K=5;

int n,ans;
int a[15][10],s[10];
bool flag;

int getnum(int x,int y){
    return (y-x+10)%10;
}

bool check(int id){    
    for(int i=1;i<=K;i++){ // change i
        if(a[id][i]==s[i]) continue;
        flag=1;
        for(int j=1;j<=K;j++){
            if(j!=i&&a[id][j]!=s[j]){
                flag=0;
                break;
            }
        }
        if(flag) return 1;
    }
    for(int i=1;i<K;i++){ // change i & i+1
        if(a[id][i]==s[i]||getnum(a[id][i],s[i])!=getnum(a[id][i+1],s[i+1])) continue;
        flag=1;
        for(int j=1;j<=K;j++){
            if(j!=i&&j!=i+1&&a[id][j]!=s[j]){
                flag=0;
                break;
            }
        }
        if(flag) return 1;
    }
    return 0;
}

void dfs(int now){
    if(now>K){
        ans++;
        for(int i=1;i<=n;i++){
            if(!check(i)){
                ans--;
                break;
            }
        }
        return;
    }
    for(int i=0;i<=9;i++){
        s[now]=i;
        dfs(now+1);
    }
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++) scanf("%d",&a[i][j]);
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}