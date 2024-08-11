#include<bits/stdc++.h>

using namespace std;

const int N=2e6+10,LINSHI=1e4;
typedef long long LL;

int n;
LL ans;
int f[LINSHI][LINSHI];
char c[N];

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",c+1);
    for(int len=2;len<=n;++len){
        for(int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            if(f[i][j]) continue;
            f[i][j]=0;
            if(len==2){
                if(c[i]==c[j]) f[i][j]=1;
            }
            else{
                for(int k=i;k<j;++k)
                    if(f[i][k] && f[k+1][j]){
                        f[i][j]=1;
                        break;
                    }
            }
            if(f[i][j]){
                ans++;
                for(int o=1;;++o){
                    if(i-o<1 || j+o>n) break;
                    if(c[i-o]!=c[j+o]) break;
                    f[i-o][j+o]=1;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}