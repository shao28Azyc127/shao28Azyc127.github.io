#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10,M=1e4+10,L=1000,LL=2e5+10;
int q[N][2],n,h,t,a[M][L],b[M][L];
bool f[M][L];
char s[LL];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%s",&n,s+1);
    int len=strlen(s+1);
    h=1,t=0;
    for(int i = 1;i < len;i++){
        if(s[i]==s[i+1]){
            q[++t][1]=i;
            q[t][2]=i+1;
            a[i][++a[i][0]]=i+1;
        }
    }
    while(h<=t){
        int x=q[h][1],y=q[h][2];
        while(x>1&&y<len&&s[x-1]==s[y+1]&&!f[x-1][y+1]){
            x--;
            y++;
            q[++t][1]=x;
            q[t][2]=y;
            f[x][y]=true;
            a[x][++a[x][0]]=y;
        }
        x=q[h][1],y=q[h][2];
        if(a[y+1][0]>0){
            for(int i = 1;i <= a[y+1][0];i++){
                if(!f[x][a[y+1][i]]){
                    f[x][a[y+1][i]]=true;
                    q[++t][1]=x;
                    q[t][2]=a[y+1][i];
                    a[x][++a[x][0]]=a[y+1][i];
                }
            }
        }
        h++;
    }
    printf("%d",t);
    return 0;
}
