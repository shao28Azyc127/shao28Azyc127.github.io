#include<bits/stdc++.h>
const int maxn=8000+5;
using namespace std;
int n;
char s[80005];
int cnt;
bool check(int x,int y){
    int vis[maxn];
    memset(vis,0,sizeof(vis));
    while(1){
        int f=0,ccnt=0;
        for(int i=x;i<=y;i++){
            int k=i+1;
            if(vis[i])continue;
            while(vis[k]==1&&k<=y)k++;
            if(s[i]==s[k]){vis[i]=0;vis[k]=0;ccnt+=2;f=1;}
        }
        if(ccnt==y-x+1)return true;
        if(f==0)return false;
    }

}
int main(){
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<n;i++)if(s[i]==s[i+1])cnt++;
    cout<<cnt;return 0;
    int len=2;
    while(len<=n){
        for(int i=1;i+len-1<=n;i++){
            if(check(i,i+len-1)){cnt++;/*cout<<i<<' '<<i+len-1<<endl;*/}
        }
        len=len*2;
    }
    printf("%d",cnt);
    return 0;
}
