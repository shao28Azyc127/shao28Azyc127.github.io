#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt;
int m[2000002],h,b,c;
int r,t;
int g[2000002];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    m[0]=-1;
    h=1;
    b=1;
    t=-1;
    for(int i=1;i<=n;i++){
        char a;
        cin>>a;
        int k;
        k=a-'a';
        if(k==t){
            h++;
        }else{
            int y=h/2;
            ans+=h-1-y;
            t=k;
            h=1;
        }
        if(m[cnt]==k){
            cnt--;
            ans++;
            b--;
            g[b]=1;
            if(r==0){
                b++;
            }
            r=1;
        }else{
            m[++cnt]=k;
            r=0;
            b++;
            g[b]=0;
        }
    }
    int y=h/2;
    ans+=h-1-y;
    int o=0;
    for(int i=1;i<=b;i++){
        if(g[i]==1){
            o++;
        }else{
            ans+=(o-1)*o/2;
            o=0;
        }
    }
    ans+=(o-1)*o/2;
    printf("%d",ans);
    return 0;
}