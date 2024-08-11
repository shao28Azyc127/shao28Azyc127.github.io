#include<bits/stdc++.h>
using namespace std;
const int NR=2e6+10;
#define ll long long
char str[NR];ll ans;
int n,f[NR],last[NR],nxt[NR],pre[NR],buc[30],sum[2][26][NR],now[30];

signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    scanf("%s",str+1);
    for(int i=1;i<=n;i++){
        if(str[i]!=str[i-1])last[i]=i;
        else last[i]=last[i-1];
        int tmp=str[i]-'a';
        pre[i]=buc[tmp];nxt[buc[tmp]]=i;
        buc[tmp]=i;
    }
    for(int c=0;c<26;c++){
        int now=0;
        for(int i=1;i<=n;i++)
            if(str[i]-'a'==c){
                now=i;
                break;
            }
        if(!now)continue;
        while(now&&nxt[now]){
            sum[0][c][now]++;sum[0][c][nxt[now]+1]--;
            now=nxt[nxt[now]];
        }
        for(int i=1;i<=n;i++)sum[0][c][i]+=sum[0][c][i-1];
        // for(int i=1;i<=n;i++)printf("%d ",sum[0][c][i]);puts("");
    }
    for(int c=0;c<26;c++){
        int now=0,pos=0;
        for(int i=1;i<=n;i++){
            if(str[i]-'a'==c&&pre[i]){
                now=i;
                break;
            }
            if(!pos&&str[i]-'a'==c)pos=i;
        }
        if(!now){
            for(int i=1;i<=pos;i++)sum[1][c][i]=1;
            continue;
        }
        sum[1][c][1]++;sum[1][c][pre[now]+1]--;
        while(now&&nxt[now]){
            sum[1][c][now]++;sum[1][c][nxt[now]+1]--;
            now=nxt[nxt[now]];
        }
        for(int i=1;i<=n;i++)sum[1][c][i]+=sum[1][c][i-1];
    }
    for(int i=1;i<=n;i++){
        if((i-last[i])&1){
            f[i]=f[i-2]+1;
            now[str[i]-'a']^=1;
        }
        else{
            // if(last[i]!=i)f[i]=1;
            if(pre[i]){
                bool flag=1;
                for(int j=0;j<26;j++)
                    if(str[i]-'a'!=j)
                        if(sum[now[j]][j][pre[i]])flag=0;
                if(flag)f[i]+=f[pre[i]-1]+1;
            }
            now[str[i]-'a']^=1;
        }
        ans+=f[i];
        // printf("i:%d last:%d pre:%d nxt:%d f:%d ans:%lld\n",i,last[i],pre[i],nxt[i],f[i],ans);
        // printf("%d\n",f[i]);
    }
    cout<<ans<<endl;
    return 0;
}