#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=8e3+5;
int n,num[N],f[N][N],cnt;
char str[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)    cin>>str[i];
    for(int i=1;i<n;i++){
        if(str[i]==str[i-1]){
            f[i-1][i]=1;
            int j=1;
            while(i-1-j>=0&&i+j<n){
                if(str[i-1-j]==str[i+j]){
                    f[i-1-j][i+j]=f[i-j][i+j-1]+1;
                    j++;
                }else   break;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=i;j--){
            for(int k=j;k>=i;k--){
                f[i][j]=max(f[i][k]+f[k+1][j]+(f[i][k]&&f[k+1][j]),f[i][j]);
            }
        }
    }
    printf("%d",f[0][n-1]);
    return 0;
}
//aaaabbbb
//a 0
//aa 1
//aaa 2
//aaaa 4
//aaaab 4
//aaaabb
