#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
int n,ans;
bool m[2001][2001];
string a;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>a;
    for(int j = 1;j<=n/2;j++){
        for(int i = j;i<=n-j;i++){
            if(a[i+j-1]==a[i-j]){
                if(m[i][j-1]||j==1){
                    ans++;
                    m[i][j]=true;
                }
            }
        }
    }
    for(int j = 1;j<=n/2;j++){
        for(int k = 1;k<=n/2;k++){
            for(int i = 1;i<=n-j-k;i++){
                if(m[i][j]&&m[i+j+k][k]&&!m[i][j+k]){
                    ans++;
                    m[i][j+k]=true;
                }
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
