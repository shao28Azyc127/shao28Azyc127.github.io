#include<bits/stdc++.h>
using namespace std;
struct IO{
    IO(){
        freopen("game.in","r",stdin);
        freopen("game.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
const int N=8007;
int n;
char s[N];
bool f[N][N];
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<n;i++){
        if(s[i]==s[i+1]){
            f[i][i+1]=true;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            if(s[i]==s[j]){
                f[i][j]=f[i+1][j-1];
            }
            for(int k=i;k<=j;k++){
                if(f[i][j]){
                    break;
                }
                f[i][j]=(f[i][k]&&f[k+1][j]?1:0);
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(f[i][j]){
                ans++;
            }
        }
    }
    cout<<n<<'\n';
    return 0;
}
