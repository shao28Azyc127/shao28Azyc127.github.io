#include<iostream>
using namespace std;
char c[20005];
bool b[20005][20005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<n;i++) if(c[i]==c[i+1]) ans++,b[i][1]=true;
    for(int i=2;i*2<=n;i++){
        for(int j=1;j+i*2-1<=n;j++){
            if(b[j+1][i-1]&&c[j]==c[j+2*i-1]){
                b[j][i]=true;
                ans++;
                continue;
            }
            for(int k=1;k<i;k++){
                if(b[j][k]&&b[j+2*k][i-k]){
                    b[j][i]=true;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
