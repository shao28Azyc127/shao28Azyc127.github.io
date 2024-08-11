#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=8005;
int n;
string s;
bool f[N][N];
ll ans;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;i++)if(s[i]==s[i+1])f[i][i+1]=1,++ans;
    for(int len=4;len<=n;len+=2){
        for(int i,j=len-1;j<n;j++){
            i=j-len+1;
            if(!f[i][j]){
                if(f[i+1][j-1]&&s[i]==s[j])f[i][j]=1;
                else for(int k=i+1;k<j;k+=2)if(f[i][k]&&f[k+1][j]){f[i][j]=1;break;}
            }
            if(f[i][j])++ans;
//            cout<<i<<' '<<j<<endl;
//            ++ans;
//            if(i>0&&j<n-1&&s[i-1]==s[j+1])f[i-1][j+1]=1;
 //           for(int k=i-2;k>0;k-=2)if(f[k][i-1])f[k][j]=1;
 //           for(int k=j+2;k<n;k+=2)if(f[j+1][k])f[i][k]=1;
        }
    }
    printf("%lld",ans);
    return 0;
}
