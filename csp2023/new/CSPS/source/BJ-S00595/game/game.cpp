#include<bits/stdc++.h>

using namespace std;

const int NR=2e6+5;

int n;
char s[NR];
int pos[NR],f[NR];
long long ans;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    s[0]='#';
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1]) pos[i]=i-1;
        else{
            int x=i-1;
            while(pos[x]){
                x=pos[x]-1;
                if(s[i]==s[x]){
                    pos[i]=x;
                    break;
                }
            }
        }
        if(pos[i]){
            f[i]=f[pos[i]-1]+1;
            ans+=1ll*f[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}